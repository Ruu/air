#ifndef AIR_BROADCASTER
#define AIR_BROADCASTER 

#include <vector>
#include <memory>
#include "air/channel.h"
#include "air/message.h"

namespace air
{
	
class broadcaster
{
public:
	void air(const std::shared_ptr<air::message> &m) const;
	void add_channel(const std::shared_ptr<channel> &ch);

private:
	std::vector<std::shared_ptr<channel>> channels;
};

}

#endif // AIR_BROADCASTER
