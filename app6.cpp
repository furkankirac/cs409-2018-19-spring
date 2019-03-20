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
#include <memory>
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

    void operator=(const Image& other)
    {
        init(other.nRows, other.nCols);
        copy(other.mem, other.mem + other.numElements(), mem);
    }

    Image(Image&& other) : nRows(other.nRows), nCols(other.nCols), mem(other.mem)
    {
        other.mem = nullptr;
    }

    void operator=(Image&& other)
    {
        clear();
        nRows = other.nRows;
        nCols = other.nCols;
        mem = other.mem;
        other.mem = nullptr;
    }

    T& operator()(int row, int col)
    {
        static T dummy;
        if(mem == nullptr)
        {
            cout << "OOOPS!" << endl;
            return dummy;
        }
        return mem[row*nCols+col];
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
//    unique_ptr<Image> unique_image(new Image(10, 20));
//    auto unique_image = unique_ptr<Image>(new Image(10, 20));
//    auto img1 = make_unique<Image>(10, 20);

    auto img1 = make_shared<Image>(100, 200);
    auto img2 = img1;
    auto img3 = img1;

    (*img1)(5, 6) = 100;

    cout << (int)(*img1)(5, 6) << endl;
    cout << (int)(*img2)(5, 6) << endl;
    cout << (int)(*img3)(5, 6) << endl;

    return 0;
}
