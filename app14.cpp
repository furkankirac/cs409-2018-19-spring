// typeid operator, std::type_info, std::type_index, std::any, std::map, std::unordered_map
// template deduction guides
// overloading lambdas

// CRTP: curiously recurring template pattern, singleton pattern example
// structured bindings

#include <iostream>
#include <variant>
#include <map>
#include <unordered_map>
#include <any>
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <tuple>

using namespace std;

template<typename T>
struct Foo
{
    T value;
    Foo(const T& value) : value{value} { }
};

Foo(const char*) -> Foo<string>; // if const char* is seen, deduce it as type "string"


// ----------------------
int main(int argc, char* argv[])
{
    auto f = Foo{"hello"}; // const char* wouldn't work by itself without deduction guide

    return 0;
}
