#ifndef AIR_CHANNEL_H
#define AIR_CHANNEL_H 

#include <memory>

namespace air
{

class message;

class channel
{
public:
	virtual ~channel() { };
	virtual void transmit(const std::shared_ptr<message> &m) = 0;
};

}

#endif // AIR_CHANNEL_H
