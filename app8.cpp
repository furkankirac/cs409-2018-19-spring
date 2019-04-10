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

template<typename T>
struct TypeDisplayer;

namespace my
{
    template<typename T1, typename T2>  struct is_same          { static const bool value = false; };
    template<typename K>                struct is_same<K, K>    { static const bool value = true; };
}



auto print = [](const auto& mat, auto printStyler)
{
    using T = decltype(mat);
//    TypeDisplayer<T> a;

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

// ----------------------
int main(int argc, char* argv[])
{
    auto img = Image{10, 10};
    img(5, 5) = 100;

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
