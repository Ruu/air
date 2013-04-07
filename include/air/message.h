#ifndef AIR_MESSAGE_H
#define AIR_MESSAGE_H

#include <memory>

namespace air
{

class channel;

//! Base message class. 
class message : public std::enable_shared_from_this<message>
{
public:
	virtual ~message() = default;

	//! 
	virtual const char *what() const = 0;

	//! The default implementation of "transmit_over" function.
	//! It simply call the "transmit" function of taken channel.
	virtual void transmit_over(std::shared_ptr<channel> &ch);
};

}

#endif // AIR_MESSAGE_H
