#include "list.hpp"
#include <catch.hpp>
#include <list>

template<typename FwdIt, typename List>
void check_equal(FwdIt begin, FwdIt end, List const* iter1) {
    for (auto iter = begin; iter != end; ++iter) {
        REQUIRE(iter1);
        CHECK(iter1->value == *iter);
    }
    CHECK(iter1 == nullptr);
}

TEST_CASE("converters") {
    std::list slist{1,2,3,4,5,6,7,8,9};
    List1 list1 = to_list1(slist);
    List2 list2 = to_list2(slist);

    check_equal(slist.cbegin(), slist.cend(), &list1);
    check_equal(slist.cbegin(), slist.cend(), &list2);

    list1 = reverse(list1);
    check_equal(slist.crbegin(), slist.crend(), &list1);
    list2 = reverse(list2);
    check_equal(slist.crbegin(), slist.crend(), &list2);

    list1 = List1{};
    list1 = to_list1(list2);
    check_equal(slist.crbegin(), slist.crend(), &list1);
    list2 = to_list2(list1);
    check_equal(slist.crbegin(), slist.crend(), &list2);

    slist = reverse(slist);
    check_equal(slist.cbegin(), slist.cend(), &list2);
}
