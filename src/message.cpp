#include "air/message.h"
#include "air/channel.h"

namespace air
{

void message::transmit_over(std::shared_ptr<channel> &ch)
{
	if (ch)
		ch->transmit(shared_from_this());
}

}