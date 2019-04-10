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

auto printImage = [](const Image& img, auto printStyler)
{
    using FUNC = decltype(printStyler);

    for(int i=0; i<img.nRows; ++i)
    {
        for(int j=0; j<img.nCols; ++j)
        {
            printStyler(img(i, j));
            if(j != img.nCols-1)
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

    char separator = '_';

    auto printStyler = [=](const Color& col) {
        cout << (int)col.r << separator << (int)col.g << separator << (int)col.b;
    };
    printImage(img, printStyler);

    printImage(img, [=](const Color& col) {
        cout << (int)col.r << "/" << (int)col.g << "/" << (int)col.b;
    });

    return 0;
}
