#ifndef __Matrix_h
#define __Matrix_h

#include <iostream>
#include <stdint.h>

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
        std::cout << "memory allocated: (" << nRows << ", " << nCols << ") = " << (numElements()*sizeof(T)) << " bytes" << std::endl;
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
        std::cout << "created" << std::endl;
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
            std::cout << "OOOPS!" << std::endl;
            return dummy;
        }
        return mem[row*nCols+col];
    }

    void clear()
    {
        delete[] mem;
        mem = nullptr;
        std::cout << "memory cleared" << std::endl;
    }

    ~Matrix()
    {
        clear();
        std::cout << "destroyed" << std::endl;
    }

    void load() override
    {
        std::cout << "Matrix loaded!" << std::endl;
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
        std::cout << "Image loaded!" << std::endl;
    }
};

#endif
