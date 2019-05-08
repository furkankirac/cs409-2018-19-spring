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


template<typename ... Ts> struct overloaded : public Ts... { using Ts::operator()...; };
template<typename ... Ts> overloaded(Ts...) -> overloaded<Ts...>;

// ----------------------
int main(int argc, char* argv[])
{
    using var_t = variant<int, float, string>;

    auto v = vector<var_t>{10.3f, "hello", 10, "world"};
    for(const auto& var : v)
    {
        visit(overloaded{
                  [](int value) { cout << "int: " << value << endl; },
                  [](float value) { cout << "float: " << value << endl; },
                  [](const string& value) { cout << "string: " << value << endl; }
                  },
              var
              );
    }

    auto a = vector<any>{10, 5.3, 3.14f, "dsfkjbkd", "djfbvakjds"s};
    for(auto A : a)
    {
        try {
            auto i = any_cast<int>(A);
            cout << "ANY int: " << i << endl;
        } catch (...) {
        }
    }


    return 0;
}
