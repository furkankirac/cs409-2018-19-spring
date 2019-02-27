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

void doIt() { }

struct Fun
{
    int volume;
    float illumination;

    static void doIt() { }

    Fun fun(double how_much)
    {
        return Fun{(int)(how_much*volume), (float)(how_much*illumination)};
    };
};

Fun fun(double how_much, int volume, float illumination)
{
    return Fun{(int)(how_much*volume), (float)(how_much*illumination)};
}

Fun fun(double how_much, Fun f)
{
    return Fun{(int)(how_much*f.volume), (float)(how_much*f.illumination)};
}


//Fun fun(double how_much)
//{
//    return Fun{(int)(how_much*100), (float)(how_much*1.0f)};
//}


int main(int argc, char* argv[])
{
    auto f = Fun{100, 10.0f};
    f.fun(5.0);

    fun(5.0, 100, 10.0f);
    fun(5.0, f);

    return 0;
}
