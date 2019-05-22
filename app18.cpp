// std::is_enum, std::is_integral
// SFINAE: Substitution Failure Is Not An Error
// std::enable_if

#include <iostream>

using namespace std;

template<typename...>
struct TypeDisplayer;

template<bool B, typename T = void>     struct EnableIf             { };
template<typename K>                    struct EnableIf<true, K>    { using type = K; };

template<bool B, typename T = void>
using EnableIf_t = typename EnableIf<B, T>::type;


// template<typename T, typename K = typename EnableIf< !is_same_v<T, int>, unsigned int >::type >
// template<typename T, typename K = EnableIf_t< !is_same_v<T, int>, unsigned int > >
//template<typename T, typename = EnableIf_t< !is_same_v<T, int> > >
//template<typename T, typename = enable_if_t< !is_same_v<T, int> > >
//void print(const T& value, enable_if_t< !is_same_v<T, int> >* = nullptr)


template<typename T>
void print(const T& value)
{
    static_assert(!is_same_v<T, float>, "I don't like floats!");

    cout << value << endl;
}

//template<> void  print(const int&) = delete;

// ----------------------
int main(int argc, char* argv[])
{
//    using AAA = EnableIf<false, int>::type;
//    auto t = TypeDisplayer<AAA>{};

//    print(10);
    print(string{"hello"});
    print(3.1415f);

    return 0;
}
