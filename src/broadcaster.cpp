#include "air/broadcaster.h"

namespace air
{

void broadcaster::air(const std::shared_ptr<air::message> &m) const
{
	for (auto ch: channels)
		m->transmit_over(ch);
}

void broadcaster::add_channel(const std::shared_ptr<channel> &ch)
{
	channels.push_back(ch);
}

}
