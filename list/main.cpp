#include "list.hpp"
#include <iostream>
#include <sstream>

int main() {
    std::cout << "Enter numbers separated by spaces\n";
    std::string str;
    std::getline(std::cin, str);
    std::istringstream ss{str};
    int x;
    if (! (ss >> x) )
        return -1;
    List1 l{x};
    List1 *out_iter = &l;
    while (ss >> x) {
        out_iter->next = std::make_unique<List1>(List1{x});
        out_iter = out_iter->next.get();
    }
    std::cout << "You have entered:\n";
    for (List1 const* iter = &l; iter != nullptr; ++iter)
        std::cout << iter->value << " ";
    std::cout << "\n";
    std::cout << "And these numbers in reverse order\n";
    List1 ll = reverse(l);
    for (List1 const* iter = &ll; iter != nullptr; ++iter)
        std::cout << iter->value << " ";
    std::cout << "\n";
    return 0;
}
