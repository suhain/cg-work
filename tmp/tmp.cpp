#include <cg/primitives/contour.h>
#include <cg/primitives/point.h>
#include <cg/operations/orientation.h>
#include <cg/operations/contains/triangle_point.h>
#include <iostream>
#include <algorithm>
#include <cg/io/point.h>
#include <cg/io/triangle.h>

int main()
{
    cg::contour_2 cont({
        {0, 0},
        {-1, 2},
        {2, 3},
        {2, 1},
        {1, -1}});

    cg::point_2 p(1, 1);
    for (auto i = cont.begin(); i != cont.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
    auto it = std::lower_bound(cont.begin() + 1, cont.end() - 1, p,
            [&](cg::point_2 const& a, cg::point_2 const& b)
            {
                return cg::orientation(*cont.begin(), a, b) == cg::CG_RIGHT;
            });
    auto x = it; x--;
    std::cout << cg::contains(cg::triangle_2(*cont.begin(), *it, *x), p) << std::endl;
    std::cout << cg::contains(cg::triangle_2(*cont.begin(), *(cont.begin() + 1), *(cont.end() - 1)), p) << std::endl;
    
    std::cout << *cont.begin() << std::endl;
    std::cout << *it << std::endl;
    std::cout << *x << std::endl;
    return 0;
}