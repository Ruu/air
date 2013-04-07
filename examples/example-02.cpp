#include <iostream>
#include <air/threaded_channel.h>

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

class dumb_console_channel : public air::channel 
{
public:
	void transmit(const std::shared_ptr<air::message> &m) 
	{
		std::cout << m->what() << std::endl;
	}
};

int main()
{
	std::shared_ptr<air::channel> console(new dumb_console_channel);
	air::threaded_channel threaded(console);

	for (int i = 0; i < 20000; ++i) 
	{
		threaded.transmit(std::shared_ptr<air::message>(
			new simple_message("Hello, World!")));
	}
}
