// functional programming: what is it?
// to "if" or not to "if"
// relations to overload resolution and template specializations (to follow)

// working with types: Type Displayer trick.
// template specializations (a functional programming primer)
// is_same, remove_const, remove_volatile, remove_cv, remove_reference, decay

// good to know: template-template types, template auto, type constructors

#include <iostream>
#include <functional>
#include <stdint.h>

#include "Matrix.h"

using namespace std;

template<typename...>
struct TypeDisplayer;

namespace my
{
    template<typename T1, typename T2>  struct is_same          { static const bool value = false; };
    template<typename K>                struct is_same<K, K>    { static const bool value = true; };

    template<typename T>                struct remove_const             { using type = T; };
    template<typename K>                struct remove_const<const K>    { using type = K; };

    template<typename T>                struct remove_volatile             { using type = T; };
    template<typename K>                struct remove_volatile<volatile K> { using type = K; };

    template<typename T>                struct remove_cv
    {
        using type = typename remove_volatile< typename remove_const<T>::type >::type;
    };

    template<typename T>                struct remove_reference      { using type = T; };
    template<typename K>                struct remove_reference<K&>  { using type = K; };
    template<typename K>                struct remove_reference<K&&> { using type = K; };

    template<typename T>                struct decay {
        using type = typename remove_cv< typename remove_reference<T>::type >::type;
    };

}

//TypeDisplayer<const int> v1;
//TypeDisplayer< my::remove_const<const int>::type > v2;

//TypeDisplayer< const volatile double > v3;
//TypeDisplayer< my::remove_cv<const volatile double>::type > v4;

//TypeDisplayer< double& > v5;
//TypeDisplayer< my::remove_reference<double&>::type > v6;

template<typename T>
auto print_older(const Image& mat, T printStyler)
{
    cout << "Printing an Image." << endl;

    using FUNC = decltype(printStyler);

    for(int i=0; i<mat.nRows; ++i)
    {
        for(int j=0; j<mat.nCols; ++j)
        {
            printStyler(mat(i, j));
            if(j != mat.nCols-1)
                cout << "|";
        }
        cout << endl;
    }
}

template<typename T>
auto print_older(const Matrix<int>& mat, T printStyler)
{
    cout << "Printing a Matrix<int>." << endl;

    using FUNC = decltype(printStyler);

    for(int i=0; i<mat.nRows; ++i)
    {
        for(int j=0; j<mat.nCols; ++j)
        {
            printStyler(mat(i, j));
            if(j != mat.nCols-1)
                cout << "|";
        }
        cout << endl;
    }
}




template<typename T1, typename T2>
auto print_old(const T1& mat, T2 printStyler)
{
    using T = typename my::decay<T1>::type;
    if constexpr(my::is_same<T, Image>::value)
        cout << "Printing an Image." << endl;
    else if constexpr(my::is_same<T, Matrix<int>>::value)
        cout << "Printing an Matrix<int>." << endl;
    else
    cout << "Printing a Matrix<T>." << endl;


    using FUNC = decltype(printStyler);

    for(int i=0; i<mat.nRows; ++i)
    {
        for(int j=0; j<mat.nCols; ++j)
        {
            printStyler(mat(i, j));
            if(j != mat.nCols-1)
                cout << "|";
        }
        cout << endl;
    }
}




auto print = [](const auto& mat, auto printStyler)
{
    using T = typename my::decay<decltype(mat)>::type;
    if constexpr(my::is_same<T, Image>::value)
        cout << "Printing an Image." << endl;
    else if constexpr(my::is_same<T, Matrix<int>>::value)
        cout << "Printing an Matrix<int>." << endl;
    else
    cout << "Printing a Matrix<T>." << endl;


    using FUNC = decltype(printStyler);

    for(int i=0; i<mat.nRows; ++i)
    {
        for(int j=0; j<mat.nCols; ++j)
        {
            printStyler(mat(i, j));
            if(j != mat.nCols-1)
                cout << "|";
        }
        cout << endl;
    }
};


template<typename T, T value>
inline void func()
{
    if constexpr(my::is_same<T, int>::value)
        cout << "This is int" << endl;

    cout << value << endl;
}

template<auto value>
inline void func_improved()
{
    using T = decltype(value);
    if constexpr(my::is_same<T, int>::value)
        cout << "This is int" << endl;

    cout << value << endl;
}

// ----------------------
int main(int argc, char* argv[])
{
    func<int, 5>();
    func_improved<5>();
    func_improved<(short)3>();
//    cout << "This is int" << endl;
//    cout << value << endl;

    auto img = Image{10, 10};
    img(5, 5) = 100;

//    static const bool s = my::is_same<int, float>::value;
//    if(s)
//        cout << "int and float are the same types" << endl;
//    else
//        cout << "int and float are NOT the same types" << endl;

//    TypeDisplayer<decltype(img)> a;


    char separator = '_';

    auto printStyler = [=](const Color& col) {
        cout << (int)col.r << separator << (int)col.g << separator << (int)col.b;
    };
    print(img, printStyler);

    print(img, [=](const Color& col) {
        cout << (int)col.r << "/" << (int)col.g << "/" << (int)col.b;
    });


    auto mat = Matrix<int>{4, 3};
    mat(2, 1) = 2;
    print(mat, [](int value) { cout << "[" << value << "]"; });

    return 0;
}
