#ifndef AIR_TEST_EMPTY_DELETER_H
#define AIR_TEST_EMPTY_DELETER_H

namespace air 
{
namespace test
{


struct empty_deleter
{
    void operator()(void *)
    {
    }
};

}
}

#endif // AIR_TEST_EMPTY_DELETER_H
