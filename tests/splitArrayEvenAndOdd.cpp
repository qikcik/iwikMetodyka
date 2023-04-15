#include <gtest/gtest.h>
#include <gmock/gmock.h>

template<typename T>
struct splitEvenAndOddResult
{
    std::vector<T> even;
    std::vector<T> odd;
};

template<typename T>
splitEvenAndOddResult<T> splitEvenAndOdd(std::vector<T> in)
{
    splitEvenAndOddResult<T> result;
    result.even.reserve(in.size()/2);
    result.odd.reserve(in.size()/2);

    for(size_t i=0;i!=in.size();i++)
    {
        if(i%2 == 0)
            result.even.push_back(in[i]);
        else
            result.odd.push_back(in[i]);
    }

    return result;
}


TEST(SplitArrayEvenAndOdd, Simple)
{
    std::vector<int> input {5,7,3,2,6,8,2,1};
    auto result = splitEvenAndOdd(input);


    ASSERT_THAT(result.even, testing::ElementsAre(5,3,6,2));
    ASSERT_THAT( result.odd, testing::ElementsAre(7,2,8,1));
}

TEST(SplitArrayEvenAndOdd, Empty)
{
    std::vector<int> input {};
    auto result = splitEvenAndOdd(input);

    ASSERT_THAT(result.even, testing::ElementsAre());
    ASSERT_THAT( result.odd, testing::ElementsAre());
}