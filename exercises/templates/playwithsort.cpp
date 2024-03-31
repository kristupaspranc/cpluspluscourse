#include "OrderedVector.hpp"
#include "Complex.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ranges>

struct ReverseStringLess {
    bool operator() (const std::string &s, const std::string &t) const {
        // TODO: compare reversed strings
        // hint: you can use:
        // - std::views::reverse
        // - std::ranges::lexicographical_compare
        // or, if your compiler does not support those yet,
        // take copies of the strings and reverse them using std::reverse
        return s < t;
    }
};

int main() {
    std::cout << "Integer\n";
    OrderedVector<int> v(10);
    for (int i = 10; i > 0; i--)
        v.add(i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string> vs(5);
    vs.add(std::string("one"));
    vs.add(std::string("two"));
    vs.add(std::string("three"));
    vs.add(std::string("four"));
    vs.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs[i] << " ";
    std::cout << "\n\n";

    // TODO: Demonstrate OrderedVector with Complex as element type similar to above
    std::cout << "Complex\n";
    OrderedVector<Complex> vc(3);
    vc.add(Complex{1,1});
    vc.add(Complex{2,2});
    vc.add(Complex{3,3});
    for (int i =0; i < 3; i++){
        std::cout << vc[i] << "\n";
    }

    // TODO: Bonus. Order complex of complex.
    Complex_t<Complex> a{Complex{1,2},Complex{3,4}};
    std::cout << a << "\n";


    // TODO: Extend OrderedVector to allow to customize the ordering via an additional template paramter.
    //       Then, demonstrate the new functionality by ordering an OrderedVector<std::string>,
    //       where the strings are compared starting at their last letters.


    // TODO: Order an OrderedVector of Complex based on the Manhattan distance


}
