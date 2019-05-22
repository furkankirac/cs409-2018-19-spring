// std::is_enum, std::is_integral
// SFINAE: Substitution Failure Is Not An Error
// std::enable_if

#include <iostream>

using namespace std;

template<typename...>
struct TypeDisplayer;

template<bool B, typename T>    struct EnableIf             { };
template<typename K>            struct EnableIf<true, K>    { using type = K; };


template<typename T, typename K = typename EnableIf< !is_same_v<T, int>, unsigned int >::type >
void print(const T& value)
{
    cout << value << endl;
}

// ----------------------
int main(int argc, char* argv[])
{
//    using AAA = EnableIf<false, int>::type;
//    auto t = TypeDisplayer<AAA>{};

    print(10);
    print(string{"hello"});
    print(3.1415f);

    return 0;
}
