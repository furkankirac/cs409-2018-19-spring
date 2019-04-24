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

struct Dummy
{
    size_t  size;
    int*    mem;

    Dummy() : size{0}, mem{nullptr} {
        cout << "default c-tor" << endl;
    }
    Dummy(const Dummy& other) : size(other.size)
    {
        cout << "copy c-tor" << endl;

        mem = new int[size];
        std::copy(other.mem, other.mem + other.size, mem);
    }
    ~Dummy()
    {
        cout << "d-tor" << endl;
        delete[] mem;
        size = 0;
    }

    friend inline void swap(Dummy& first, Dummy& second)
    {
        using std::swap;

        swap(first.size, second.size);
        swap(first.mem, second.mem);
    }

    Dummy(Dummy&& other) : Dummy() // move c-tor
    {
        cout << "move c-tor" << endl;
        swap(*this, other);
    }

    void operator=(Dummy other) // copy assign
    {
        cout << "assignment" << endl;
        swap(*this, other);
    }
};

Dummy func(int i)
{
    auto d = Dummy{};
    return d;
}

// ----------------------
int main(int argc, char* argv[])
{
    auto a = func(10);

    return 0;
}
