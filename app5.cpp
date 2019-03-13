// Vec2d, Vec3d, templates (typename, non-type param)
// CV qualifiers: const, volatile
// const, mutable
// inheritance
// dynamic polymorphism, v-table, __v_ptr attribute

#include <iostream>
#include <array>

#include <utility> // for std::pair
#include <tuple>

using namespace std;

struct VecBase
{
    virtual void print() const { }
    virtual void blabla() const { }
};

template<int nDims, typename T = int>
struct __attribute__((packed, aligned(1))) Vec : public VecBase {
//    char a;
    array<T, nDims> values;

    template<typename... Ts>
    Vec(Ts... values) : values{values...}
    { }

//    Vec(array<T, nDims> values) : extra_data{nDims}, values{values}
//    {
//    }

    auto dot_product(const Vec<nDims, T> b) const
    {
        auto sum = T{};
        for(int i=0; i<nDims; ++i)
            sum += values[i]*b.values[i];
        return sum;
    }

    void print() const
    {
        cout << "[";
        for(int i=0; i<nDims; ++i) {
            if(i!=0)
                cout << ", ";
            cout << values[i];
        }
        cout << "]" << endl;
    }

};

// ----------------------
int main(int argc, char* argv[])
{
    cout << Vec<2>{10, 20}.dot_product({5, 3}) << endl;
    cout << Vec<3>{10, 20, 1}.dot_product({5, 3, 2}) << endl;
    cout << "-----" << endl;

    auto v1 = Vec<2>{10, 20};
    auto v2 = Vec<3>{10, 20, 1};

//    auto vec_array = array<VecBase*, 2>{ &v1, &v2 };
//    for(int i=0; i<2; ++i)
//        vec_array[i]->print();

    cout << "Size of v1 (2dim) = " << sizeof(v1) << endl;
    cout << "Size of v2 (3dim) = " << sizeof(v2) << endl;

    return 0;
}
