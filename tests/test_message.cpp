#include <gmock/gmock.h>
#include <air/channel.h>
#include <air/message.h>
#include <test/empty_deleter.h>

using ::testing::_;
using namespace air;
using namespace air::test;

struct mock_channel : public channel
{
	MOCK_METHOD1(transmit, void(const std::shared_ptr<message> &m));
};

struct test_message : public message
{
	const char *what() const 
	{
		return nullptr;
	}
};

TEST(message, should_transmit_itself_over_channel)
{
	mock_channel ch;
	EXPECT_CALL(ch, transmit(_));
	std::shared_ptr<channel> ch_ptr(&ch, empty_deleter());

	std::shared_ptr<message> msg(new test_message);
	msg->transmit_over(ch_ptr);
}
