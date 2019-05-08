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

struct Lambda1
{
    auto operator()(int value) const { cout << "int: " << value << endl; }
};

struct Lambda2
{
    auto operator()(float value) const { cout << "float: " << value << endl; }
};

struct Lambda3
{
    auto operator()(const string& value) const { cout << "string: " << value << endl; }
};

struct Lambdas : public Lambda1, public Lambda2, public Lambda3
{
    using Lambda1::operator (), Lambda2::operator (), Lambda3::operator ();
};


template<typename ... Ts>
struct overloaded : public Ts...
{
    using Ts::operator()...;
};




// ----------------------
int main(int argc, char* argv[])
{
    using var_t = variant<int, float, string>;

    int i = 5;

//    auto l1 = Lambda1{};
    auto l1 = [](int value) { cout << "int: " << value << endl; };
//    auto l2 = Lambda2{};
    auto l2 = [](float value) { cout << "float: " << value << endl; };
//    auto l3 = Lambda3{};
    auto l3 = [](const string& value) { cout << "string: " << value << endl; };

    //    auto ls = Lambdas{};
//    auto ls = overloaded<decltype(l1), decltype(l2), decltype(l3)>{};

    l1(10);
    l2(10.3f);
    l3("hello");

//    ls(10);
//    ls(10.3f);
//    ls("hello");


    auto v = vector<var_t>{10.3f, "hello", 10, "world"};
    for(const auto& var : v)
    {

    }


    return 0;
}
