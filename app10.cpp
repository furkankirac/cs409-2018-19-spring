// Friend functions
// ADL: Argument dependent lookup
// Always prefer non-member (free) non-friend functions first
// Copy-swap Idiom:
// - Any class that manages a resource (a wrapper, like a smart pointer)
//   needs to implement The Big Three. (And The Big Four after C++11: move semantics)
//   Conceptually, it works by using the copy-constructor's functionality to
//   create a local copy of the data, then takes the copied data with a swap function,
//   swapping the old data with the new data. The temporary copy then destructs,
//   taking the old data with it. We are left with a copy of the new data.

// RVO: return value optimization
// CRTP: curiously recurring template pattern

// union, std::variant
// std::map, std::any
// structured bindings

#include <iostream>
#include <variant>

using namespace std;

// ----------------------
int main(int argc, char* argv[])
{
    return 0;
}
