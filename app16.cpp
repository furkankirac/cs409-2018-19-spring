// std::reference_wrapper
// threads --> std::thread: func*, functor, lambda
// tasks --> std::async: future, promise

// structured bindings: pair, map examples

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct Foo
{
    int a = 1;
    float f = 2.0f;
    double d = 3.0;
};

//template<typename T1, typename T2>
//struct Pair
//{
//    T1 first;
//    T2 second;
//};

auto bar() -> pair<Foo, int>
{
    auto foo = Foo{10, 20.0f, 30.0};
    int sum = 100;
    // ...
    return {foo, sum};
}

template<typename T, typename FUNC>
inline void Sort(T& v, FUNC func)
{
    sort(v.begin(), v.end(), func);
}

// ----------------------
int main(int argc, char* argv[])
{
    auto [foo, intval] = bar();
    cout << foo.a << endl;
    cout << foo.f << endl;
    cout << foo.d << endl;

    auto m = map<string, int>{
        {"hello", 1},
        {"world", 2}
    };

    for(const auto& [key, value] : m)
        cout << "Key=" << key << ", Value=" << value << endl;

    auto v = vector{10, -5, 20, 30, -3};
    Sort(v, [](int a, int b) {
        return b < a;
    });
    for(auto val : v)
        cout << val << endl;

    return 0;
}
