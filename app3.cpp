// this ptr, static functions
// functions vs function parameters
// methods vs objects

// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment

// operator overloading
// user-defined literals
// almost always auto - aaa rule: move type to the right
// unified/universal initialization

// namespaces
// inheritance
// dynamic polymorphism, v-table

#include <iostream>
#include <vector>

struct Int
{
    int value;

    Int() : value{0} { }
    Int(int value) : value{value} { }
    Int(const Int& other) : value{other.value} { }
};

struct Huge
{
    Int x;
    Int y;
    std::vector<int> v;

    Huge() : x{10}, y{20}, v(100)
    {
        std::cout << "Calisiyor" << std::endl;
    }

    Huge(const Huge& other) : x{other.x}, y{other.y}, v(other.v)
    {
        std::cout << "copy ctor" << std::endl;
    }

    void operator=(const Huge& right)
    {
        x = right.x;
        y = right.y;
        v = right.v;

        std::cout << "copy assignment" << std::endl;
    }

    ~Huge()
    {
        std::cout << "Siliyorum" << std::endl;
    }
};





int main(int argc, char* argv[])
{
    Huge h; // default construction
    Huge h2(h); // copy-construction
    Huge h3 = h2; // copy-construction

    Huge h4;
    h4 = h3;

//    int a = 10;
//    int const * const p = &a;
//    *p = 20;


    return 0;
}
