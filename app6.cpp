// implement Image class: ctor, dtor, copy-ctor, move-ctor, copy-assign, move-assign
// inline functions
// make it a unique instance: deleted copy-ctor, deleted copy-assign?
// smart pointers: unique_ptr, shared_ptr

// Split image class into Matrix and Image
// inheritance: abstract functions

// explicit constructors

// dynamic_cast

// trailer of future lectures:
// static_cast, const_cast, reinterpret_cast
// curiously recurring template pattern (CRTP)
// template parameters binding with runtime parameter types
// template-template types, template auto, type constructors

#include <iostream>
//#include <memory>
//#include <vector>
#include <stdint.h>
//#include <assert.h>

using namespace std;

class Image
{
public:
    using T = uint8_t; // mapped to unsigned char in background. sending to cout prints a char

    int nRows, nCols;
    T* mem;

    void init(int nRows, int nCols)
    {
        clear();
        this->nRows = nRows;
        this->nCols = nCols;
        mem = new T[nRows*nCols];
        cout << "memory allocated: (" << nRows << ", " << nCols << ") = " << (nRows*nCols*sizeof(T)) << " bytes" << endl;
    }

    Image(int nRows, int nCols) : nRows(nRows), nCols(nCols), mem(nRows*nCols == 0 ? nullptr : new T[nRows*nCols])
    {
        cout << "created" << endl;
        cout << "memory allocated: (" << nRows << ", " << nCols << ") = " << (nRows*nCols*sizeof(T)) << " bytes" << endl;
    }

    Image() : Image(0, 0) // delegated ctor
    {
    }

    void clear()
    {
        delete[] mem;
        mem = nullptr;
        cout << "memory cleared" << endl;
    }

    ~Image()
    {
        clear();
        cout << "destroyed" << endl;
    }

};

// ----------------------
int main(int argc, char* argv[])
{
    Image img(10, 20); // allocate image of 10x20
    img.clear(); // clears it

    img.init(30, 10); // reinitializes already created img

    return 0;
}
