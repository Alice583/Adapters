#include <iostream>
#include <map>
//#include <ranges>
#include <string>
#include <vector>
#include <drop.h>



int main() {
    std::vector<int> nya = {2, 3, 5, 6};
    auto c = nya | drop(2);
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << ' ';
    }
//    std::vector<int> v = {1, 2, 3, 4, 5};
//    auto it = v | std::ranges::views::drop(55);
//    std::cout << *it.begin();
}
