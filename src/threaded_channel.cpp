#include "air/threaded_channel.h"

namespace air
{

threaded_channel::threaded_channel(const std::shared_ptr<air::channel> &ch)
	: is_running(true), wrapped_channel(ch)
{
	worker = std::thread([&] {
		std::unique_lock<std::mutex> lock(mutex);
		do {
			condition_variable.wait(lock, [&]{
				return !message_queue.empty() || !is_running;
			});

			while (!message_queue.empty()) {
				wrapped_channel->transmit(message_queue.front());
				message_queue.pop();
			}
		} while (is_running);
	});
}

threaded_channel::~threaded_channel()
{
	{
		std::lock_guard<std::mutex> lock(mutex);

		is_running = false;
		condition_variable.notify_one();
	}

	worker.join();
}

void threaded_channel::transmit(const std::shared_ptr<message> &m)
{
	std::lock_guard<std::mutex> lock(mutex);

	message_queue.push(m);
	condition_variable.notify_one();
}

}
