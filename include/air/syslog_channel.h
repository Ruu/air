#ifndef AIR_CHANNEL_SYSLOG_H
#define AIR_CHANNEL_SYSLOG_H

#include "air/channel.h"
#include "air/message.h"

namespace air
{

class syslog_channel
{
public:
	syslog_channel(const std::string &logname, int facility);
	~syslog_channel();

	void transmit(const std::shared_ptr<message> &m);
};

}

#endif // AIR_CHANNEL_SYSLOG_H
