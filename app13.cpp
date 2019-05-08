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

auto typeNames = unordered_map<type_index, string>{
    { type_index(typeid(int)), "int" },
    { type_index(typeid(double)), "double"},
    { type_index(typeid(const char*)), "const char*"}
};

template<typename T>
inline void printType(T)
{
    cout << typeNames[type_index(typeid(T))] << endl;
}

// ----------------------
int main(int argc, char* argv[])
{
    using var_t = variant<int, float, double, const char*>;

    auto V = vector<var_t>{5, 5.0, 5.0f, "hello"};

    auto int_v = 5;
    auto double_v = 5.0;

    auto v = tuple<int, double>{5, 5.0};

    printType(int_v);
//    {
//        const type_info& ti = typeid(double_v);
//        cout << ti.name() << endl;
//    }
//    {
//        const type_info& ti = typeid(v);
//        cout << ti.name() << endl;
//    }


    return 0;
}
