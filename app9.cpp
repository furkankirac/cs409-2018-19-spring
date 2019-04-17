// brace initialization, std::initializer_list

// variadic parameters
// variadic templates: printAll: old style recursion, simplified if version
// pack expansion
// initializer_list trick for runOnAll
// fold expressions

// A fancy clever constructor example

// ADL: Argument dependent lookup
// RVO: return value optimization
// CRTP: curiously recurring template pattern

// std::variant, std::map, std::any
// structured bindings

#include <iostream>
#include <vector>

using namespace std;

struct Foo
{
    Foo(int a, int b)
    {
        cout << "I have two integer parameters passed." << endl;
    }

    Foo(initializer_list<int> list)
    {

    }

};


// ----------------------
int main(int argc, char* argv[])
{
    auto foo = Foo(10, 20);

    auto v1 = vector<int>{10, 20, 30}; // a vector containing 3 integers whose values are 10, 20, 30
    auto v2 = vector<int>{10}; // a vector containing 1 integer whose value is 10
    auto v3 = vector<int>(10); // a vector containing 10 integers whose values are 0.

    auto a = std::initializer_list<int>{1, 5, 10};

    for(int a : {10, 20, 30}) // {10, 20, 30} is now deduces as initializer_list<int>
        cout << a << endl;

    return 0;
}
