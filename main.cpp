#include <iostream>
#include <range/v3/all.hpp>

namespace views = ranges::views;

int
main()
{
    std::vector<int> vec{5, 4, 3, 2, 7, 8, 9, 1, 0, 6};

    auto v = vec | views::reverse | views::drop(3) | views::take(3);
    std::cout << v << std::endl;
    std::cout << views::all(vec) << std::endl;
    // 	ranges::reverse(vec);
    ranges::sort(vec | views::reverse | views::drop(3));
    std::cout << views::all(vec) << std::endl;
}