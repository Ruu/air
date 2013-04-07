#include <gmock/gmock.h>
#include <air/broadcaster.h>
#include <test/empty_deleter.h>

using ::testing::_;

struct mock_message : public air::message 
{
	MOCK_CONST_METHOD0(what, const char *());
	MOCK_METHOD1(transmit_over, void(std::shared_ptr<air::channel> &ch));
};

struct mock_channel : public air::channel
{
	MOCK_METHOD1(transmit, void(const std::shared_ptr<air::message> &m));
};

TEST(broadcaster, should_not_air_message_if_empty)
{
	mock_message message;
	EXPECT_CALL(message, transmit_over(_)).Times(0);

	air::broadcaster b;
	b.air(std::shared_ptr<air::message>(&message, air::test::empty_deleter()));
}

TEST(broadcaster, should_air_message)
{
	mock_message message;
	EXPECT_CALL(message, transmit_over(_));

	air::broadcaster b;
	b.add_channel(std::shared_ptr<air::channel>(new mock_channel));
	b.air(std::shared_ptr<air::message>(&message, air::test::empty_deleter()));
}
