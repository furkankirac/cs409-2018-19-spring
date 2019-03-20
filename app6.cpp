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
#include <vector>
#include <stdint.h>
//#include <assert.h>

using namespace std;

struct MatrixCore
{
    virtual void load() = 0;
};

template<typename T>
class Matrix : public MatrixCore
{
public:
    int nRows, nCols;
    T* mem;

    void printMemoryUsage() const
    {
        cout << "memory allocated: (" << nRows << ", " << nCols << ") = " << (numElements()*sizeof(T)) << " bytes" << endl;
    }

    size_t numElements() const { return static_cast<size_t>(nRows*nCols); }

    void init(int nRows, int nCols)
    {
        clear();
        this->nRows = nRows;
        this->nCols = nCols;
        mem = new T[numElements()];
        printMemoryUsage();
    }

    Matrix(int nRows, int nCols) : nRows(nRows), nCols(nCols), mem(numElements() == 0 ? nullptr : new T[numElements()])
    {
        cout << "created" << endl;
        printMemoryUsage();
    }

    Matrix() : Matrix(0, 0) // delegated ctor
    {
    }

    Matrix(const Matrix& other) : Matrix(other.nRows, other.nCols)
    {
        copy(other.mem, other.mem + other.numElements(), mem);
    }

    void operator=(const Matrix& other)
    {
        init(other.nRows, other.nCols);
        copy(other.mem, other.mem + other.numElements(), mem);
    }

    Matrix(Matrix&& other) : nRows(other.nRows), nCols(other.nCols), mem(other.mem)
    {
        other.mem = nullptr;
    }

    void operator=(Matrix&& other)
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
//        if(mem == nullptr)
        if(!mem)
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

    ~Matrix()
    {
        clear();
        cout << "destroyed" << endl;
    }

    void load() override
    {
        cout << "Matrix loaded!" << endl;
    }

};

struct Color
{
    uint8_t r, g, b;

    Color() : Color(0) { }
    /*explicit */Color(uint8_t illum) : r(illum), g(illum), b(illum) { }
    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) { }
};


struct Image : public Matrix<Color>
{
    using Matrix<Color>::Matrix;
    using Matrix<Color>::operator=;

    void load() override
    {
        cout << "Image loaded!" << endl;
    }
};


// ----------------------
int main(int argc, char* argv[])
{
//    unique_ptr<Image> unique_image(new Image(10, 20));
//    auto unique_image = unique_ptr<Image>(new Image(10, 20));
//    auto img1 = make_unique<Image>(10, 20);

    Matrix<uint16_t> mat(10, 10);
    Image img1;
    Image img2;
    img1(5, 6) = Color(10, 20, 255);
    img1(5, 6) = (char)100;

    auto objects = vector<MatrixCore*>{ &img1, &mat, &img2 };
    for(auto obj : objects)
    {
        auto img_ptr = dynamic_cast<Image*>(obj);
        if(img_ptr/* != nullptr*/)
            img_ptr->load();
    }


//    auto img1 = make_shared<Image>(100, 200);
//    auto img2 = img1;
//    auto img3 = img1;

//    (*img1)(5, 6) = 100;

//    cout << (int)(*img1)(5, 6) << endl;
//    cout << (int)(*img2)(5, 6) << endl;
//    cout << (int)(*img3)(5, 6) << endl;

    return 0;
}
