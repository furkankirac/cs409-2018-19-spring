// variables and functions and scope
//   primitive types
//   local, global, static variables
//   free, member, static functions
//   function return types

// auto

// console: std::cout, std::cin

// function overloading
// operator overloading

// struct, class, ctor/dtor
// inheritance

#include <iostream>

void doIt(); // forward declaration


unsigned short a = 0; // size may change: 16, 32, 64 bits?

using namespace std;


void doIt() // definition of the function
{
    // static local variables are actually global variables
    // they get initialized only once when they are first used.
    static bool isInitialized = false;
    if(!isInitialized)
    {
        isInitialized = true;
        cout << "Now initializing..." << endl;
    }

    static int v = 100;
    cout << v << endl;
    ++v;
}

float jump(int height)
{
    return height/2;
}


//typedef int MyType;
using MyType = int;

//typedef struct
//{
//    int x;
//    int y;
//} Coordinate;

struct Coordinate
{
    int x;
    int y;

    void print()
    {
        int x = 5;
        cout << "x = " << this->x << endl;
        cout << "y = " << y << endl;
    }
};

void print(Coordinate koordinat)
{
    cout << "x = " << koordinat.x << endl;
    cout << "y = " << koordinat.y << endl;
}

void print()
{
    cout << "Hi there, how are you?" << endl;
}


int main(int argc, char* argv[])
{
    print();

    int height;
    cin >> height;
    auto new_height = jump(height);
    cout << new_height << endl;


    Coordinate coord{100, 200};
    print(coord);
//    coord.print();


//    doIt();
//    doIt();
//    doIt();

//    int actual_height = jump(10);
//    cout << actual_height << endl;
    return 0;
}
