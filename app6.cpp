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

    void printMemoryUsage() const
    {
        cout << "memory allocated: (" << nRows << ", " << nCols << ") = " << (numElements()*sizeof(T)) << " bytes" << endl;
    }

    size_t numElements() const { return (size_t)(nRows*nCols); }

    void init(int nRows, int nCols)
    {
        clear();
        this->nRows = nRows;
        this->nCols = nCols;
        mem = new T[numElements()];
        printMemoryUsage();
    }

    Image(int nRows, int nCols) : nRows(nRows), nCols(nCols), mem(numElements() == 0 ? nullptr : new T[numElements()])
    {
        cout << "created" << endl;
        printMemoryUsage();
    }

    Image() : Image(0, 0) // delegated ctor
    {
    }

    Image(const Image& other) : Image(other.nRows, other.nCols)
    {
        copy(other.mem, other.mem + other.numElements(), mem);
    }

    T get(int row, int col) const
    {
        return mem[row*nCols+col];
    }

    void set(int row, int col, T value)
    {
        mem[row*nCols+col] = value;
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
    Image img1(10, 20); // allocate image of 10x20
    img1.set(5, 6, 100);

    Image img2(img1); // copy-ctor

    cout << (int)img1.get(5, 6) << endl;
    cout << (int)img2.get(5, 6) << endl;

    return 0;
}
