#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C"
{
#include "max.h"
}

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("max")
{
   
    int numbers1[] = {5, 10, 20, 6, 10, -1, 9};
    REQUIRE(max(numbers1, 7) == 20);

    int numbers2[] = {5, 1, 4};
    REQUIRE(max(numbers2, 3) == 5);

}


