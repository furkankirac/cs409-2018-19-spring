// reference collapsing rules
// auto&&, template<typename T> T&& : perfect forwarding

// std::is_enum, std::is_integral
// SFINAE: Substitution Failure Is Not An Error
// std::enable_if

#include <iostream>

using namespace std;

template<typename...>
struct TypeDisplayer;




//void bar(int& r)    { cout << "bar: int&" << endl; }
//void bar(int&& rr)  { cout << "bar: int&&" << endl; }


//void foo(int& r)    { cout << "foo: int&" << endl;  bar(r); }
//void foo(int&& rr)  { cout << "foo: int&&" << endl; bar(move(rr)); }

template<typename T>
void bar(T&& rr)
{
    if constexpr(is_same_v<T, int>)
        cout << "bar: int&&" << endl;
    else
        cout << "bar: int&" << endl;
//    bar(forward<T>(rr));
}


template<typename T>
void foo(T&& rr)
{
//    cout << "foo: int&&" << endl;
    bar(forward<T>(rr));
}


// ----------------------
int main(int argc, char* argv[])
{
    using T1 = int;
    using T2 = int&;
    using T3 = int&&;

//    auto t1 = TypeDisplayer<T1, T2, T3>{}; // obvious

//    auto t2 = TypeDisplayer<T1, T1&, T1&&>{}; // obvious
//    auto t3 = TypeDisplayer<T2, T2&, T2&&>{}; // int&, int& & -> int&, int& && -> int&
//    auto t4 = TypeDisplayer<T3, T3&, T3&&>{}; // int&&, int&& & -> int&, int&& && -> int&&
    // reference collapsing rule table
    //  & &  -> &
    //  & && -> &
    // && &  -> &
    // && && -> &&

//    foo(5); // T -> int, T&& -> int&&

    int a = 5;
    foo(a); // T -> int&, T&& -> int& && -> int&

    return 0;
}
