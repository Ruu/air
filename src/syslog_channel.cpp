#include "air/syslog_channel.h"
#include <string>
#include <syslog.h>

namespace air
{

syslog_channel::syslog_channel(const std::string &ident, int facility)
{
	openlog(ident.c_str(), LOG_CONS | LOG_PID | LOG_NDELAY, facility);
}

syslog_channel::~syslog_channel()
{
	closelog();
}

void syslog_channel::transmit(const std::shared_ptr<message> &m)
{
	syslog(LOG_INFO, m->what());
}

}
