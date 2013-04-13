#include <string>
#include <syslog.h>
#include <air/syslog_channel.h>

class simple_message : public air::message {
public:
	explicit simple_message(const char *e) : event(e) 
	{
	}

	const char *what() const 
	{
		return event.c_str();
	}

private:
	std::string event;
};

int main()
{
	air::syslog_channel channel("air_example_03", LOG_LOCAL0);
	for (int i = 0; i < 100; ++i) 
	{
		channel.transmit(std::shared_ptr<air::message>(
			new simple_message("Hello, World!")));
	}
}
