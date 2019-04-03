// know-it: always shared_ptr + deferred d-tor as garbage col. <---> Java's way

// in compiled machine code there is only executable code and non-executable data
// consider executable code as one big function.
// we emulate our so-called "functions" by loading/saving from/to stack
//   and jumping to different locations of machine language executable
// so "functions" are only our abstractions. they are portions of exe. code.
// you cannot create a new function at run-time. (there are exceptions)
// all functions are created at compile-time.

// function pointers: printWithStyleA, printWithStyleB
// function objects: PrintWithStyleA, PrintWithStyleB
// how to pass any one of PrintWithStyleA or PrintWithStyleB?
//  bad solution: inheritance and virtual functions.
//  (resolved at run-time but we know details about it at compile-time)
//  better solution: std::function. works with any callable. still run-time resolved
//  probably best solution: templates + lambdas

// new way of defining functions: lambdas: in-line function object instantiation

// following lectures:
// lambdas in detail
// template parameters binding with runtime parameter types
// template-template types, template auto, type constructors
// curiously recurring template pattern (CRTP)

#include <iostream>
#include <stdint.h>

#include "Matrix.h"

using namespace std;

// ----------------------
int main(int argc, char* argv[])
{
    Image img(10, 10);

    return 0;
}
