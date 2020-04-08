#pragma once
#include <memory>
#include <list>

struct List1 {
    int value;
    std::unique_ptr<List1> next = nullptr; // To silence warning
};

struct List2 {
    int value;
    List2 *prev = nullptr;
    std::unique_ptr<List2> next = nullptr; // To silence warning
};

List1 to_list1(List2 const& list2);
List1 to_list1(std::list<int> const& list);
List2 to_list2(List1 const& list1);
List2 to_list2(std::list<int> const& list);

List1 reverse(List1 const& list);
List2 reverse(List2 const& list);
std::list<int> reverse(std::list<int> const& list);
