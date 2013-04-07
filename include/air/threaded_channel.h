#ifndef AIR_THREADED_CHANNEL_H
#define AIR_THREADED_CHANNEL_H 

#include <queue>
#include <memory>
#include <thread>
#include <functional>
#include <condition_variable>
#include "air/channel.h"
#include "air/message.h"

namespace air
{

class threaded_channel : public channel
{
public:
	threaded_channel(const std::shared_ptr<air::channel> &ch);
	~threaded_channel();

	void transmit(const std::shared_ptr<message> &m);

	void set_predicate(const std::function<bool()> &pred);
	void clear_predicate();

private:
	bool is_running;
	std::mutex mutex;
	std::thread worker;
	std::condition_variable condition_variable;
	std::queue<std::shared_ptr<message>> message_queue;

	std::shared_ptr<channel> wrapped_channel;
};

}

#endif // AIR_THREADED_CHANNEL_H
