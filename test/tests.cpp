#include <iostream>
#include <gtest/gtest.h>
#include <ranges>
#include "lib/take.h"
#include "lib/drop.h"
#include "lib/reverse.h"
#include "lib/filter.h"
#include "lib/transform.h"
#include "lib/keys.h"
#include "lib/values.h"

auto func1 = [](int i) { return i * 3; };
auto func2 = [](int i) { return i % 3 == 0; };

std::vector<int> v = {10, 20, 30, 40, 50};

std::map<int, std::string> map = {
        {1, "aaa"}, {2, "bbb"}, {3, "ccc"}
};

TEST(Ranges_Test, DropTest) {
    auto lib_c = v | std::ranges::views::drop(2);
    auto lib_my = v | drop(2);

    std::vector<int> res_lib_c;
    std::vector<int> result_my;

    for (auto i : lib_c) { res_lib_c.push_back(i); }
    for (auto i : lib_my) { result_my.push_back(i); }

    ASSERT_EQ(res_lib_c, result_my);
}

TEST(Ranges_Test, TakeTest) {
    auto lib_c = v | std::ranges::views::take(2);
    auto lib_my = v | take(2);

    std::vector<int> res_lib_c;
    std::vector<int> result_my;

    for (auto i : lib_c) { res_lib_c.push_back(i); }
    for (auto i : lib_my) { result_my.push_back(i); }

    ASSERT_EQ(res_lib_c, result_my);
}

TEST(Ranges_Test, FilterTest) {
    auto lib_c = v | std::ranges::views::filter(func2);
    auto lib_my = v | filter(func2);

    std::vector<int> res_lib_c;
    std::vector<int> result_my;

    for (auto i : lib_c) { res_lib_c.push_back(i); }
    for (auto i: lib_my) { result_my.push_back(i); }

    ASSERT_EQ(res_lib_c, result_my);
}

TEST(Ranges_Test, ReverseTest) {
    auto lib_c = v | std::ranges::views::reverse;
    auto lib_my = v | reverse();

    std::vector<int> res_lib_c;
    std::vector<int> result_my;

    for (auto i : lib_c) { res_lib_c.push_back(i); }
    for (auto i : lib_my) { result_my.push_back(i); }

    ASSERT_EQ(res_lib_c, result_my);
}

TEST(Ranges_Test, KeysTest) {
    auto lib_c = map | std::ranges::views::keys;
    auto lib_my = map | keys();

    std::vector<int> res_lib_c;
    std::vector<int> result_my;

    for (auto i : lib_c) { res_lib_c.push_back(i); }
    for (auto i : lib_my) { result_my.push_back(i); }

    ASSERT_EQ(res_lib_c, result_my);
}

TEST(Ranges_TestSuite, ValuesTest) {
    auto lib_c = map | std::ranges::views::values;
    auto lib_my = map | values();

    std::vector<std::string> res_lib_c;
    std::vector<std::string> result_my;

    for (auto i : lib_c) { res_lib_c.push_back(i); }
    for (auto i : lib_my) { result_my.push_back(i); }

    ASSERT_EQ(res_lib_c, result_my);
}