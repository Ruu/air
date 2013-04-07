#include <string>
#include <iostream>
#include <air/broadcaster.h>

class simple_message : public air::message 
{
public:
	explicit simple_message(const char *event) : m_event(event)
	{
	}

	const char *what() const 
	{
		return m_event.c_str();
	}

private:
	std::string m_event;
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

	air::broadcaster broadcaster;
	broadcaster.add_channel(console);

	broadcaster.air(std::shared_ptr<air::message>(new simple_message("Hello, World!")));
}
