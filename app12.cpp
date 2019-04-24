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
#include <vector>

using namespace std;

union Value
{
    int i;
    float f;
    double d;
};

enum ValueType { INT, FLOAT, DOUBLE };

struct Foo
{
    Value value;
    ValueType type;

    explicit Foo(int v) : type{INT} { value.i = v; }
    explicit Foo(float v) : type{FLOAT} { value.f = v; }
    explicit Foo(double v) : type{DOUBLE} { value.d = v; }

    void print() const
    {
        if(type == INT)
            cout << value.i << endl;
        else if(type == FLOAT)
            cout << value.f << endl;
        else
            cout << value.d << endl;
    }
};

// ----------------------
int main(int argc, char* argv[])
{
    auto a = Foo{10};
    a.print();

    a.value.f = 3.14f;
    a.type = FLOAT;
    a.print();

    auto v = variant<int, float, double>{};
    v = 10;
    v = 3.14f;
    v = 8.0;

    try {
        cout << get<double>(v) << endl;
    } catch (...) {
        cout << "error!" << endl;
    }

    std::visit([](auto&& value) {
        using T = decay_t<decltype(value)>;
        if constexpr(is_same_v<T, int>)
            cout << "int" << endl;
        else if constexpr(is_same_v<T, float>)
            cout << "float" << endl;
        else if constexpr(is_same_v<T, double>)
            cout << "double" << endl;
    }, v);

    using VAR = variant</*int, float, double, */const char*>;
    auto vec = vector<VAR>{/*3, 10.0, 3.14f, */"hello"};

    cout << endl;

    for(auto&& var : vec)
    {
        std::visit([](auto&& value) {
            cout << value << endl;
            using T = decay_t<decltype(value)>;
            if constexpr(is_same_v<T, int>)
                cout << "int" << endl;
            else if constexpr(is_same_v<T, float>)
                cout << "float" << endl;
            else if constexpr(is_same_v<T, double>)
                cout << "double" << endl;
            else if constexpr(is_same_v<T, const char*>)
                cout << "char*" << endl;
        }, var);
    }




    return 0;
}
