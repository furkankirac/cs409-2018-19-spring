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
    Foo(int a, int b) { cout << "I have two integer parameters passed." << endl; }
    Foo(initializer_list<int> list) { }
};

// printf("here comes a decimal: %d, and this is a string %s\n", "blabla", 5); // oops problem

void printAll_old(const char* title, ...)
{
    va_list args;
    va_start(args, title);
    while(true)
    {
        int value = va_arg(args, int);
        if(value == 0)
            break;
        cout << value << endl;
    }
}


void print() { }

template<typename First, typename ... Rest> // First is a type, Rest is a lot of types (parameter pack)
inline void print(First first, Rest ... rest)
{
    cout << first << endl;
    print(rest...); // parameter pack expansion
}

// ----------------------
int main(int argc, char* argv[])
{
    print(10, "hello", 20.0); // int, const char*, double

//    print("hello", 20.0); // const char*, double
//    print(20.0); // double
//    print(); //


//    printAll_old("title", 500, 100, 200, 1000, 2000, 3000, 0);

//    auto foo = Foo(10, 20);

    return 0;
}
