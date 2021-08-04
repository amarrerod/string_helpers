
#include <catch2/catch.hpp>

#include "../include/StringHelpers.h"

using namespace std::string_literals;
TEST_CASE("Test of StringHelper", "[StringHelper]") {
    SECTION("Uppering a string") {
        auto ut{string_helper::to_upper("this is not UPPERCASE"s)};
        auto expected{"THIS IS NOT UPPERCASE"s};
        REQUIRE(expected == ut);
    }

    SECTION("Lowering a string") {
        auto lt{string_helper::to_lower("THIS IS NOT lowercase"s)};
        auto expected{"this is not lowercase"s};
        REQUIRE(expected == lt);
    }

    SECTION("Reversing a string") {
        auto rt{string_helper::reverse("cookbook"s)};
        auto expected{"koobkooc"s};
        REQUIRE(expected == rt);
    }
}