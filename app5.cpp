// Vec2d, Vec3d, templates (typename, non-type param)
// CV qualifiers: const, volatile
// const, mutable
// inheritance
// dynamic polymorphism, v-table

#include <iostream>
#include <array>

#include <utility> // for std::pair
#include <tuple>

using namespace std;


//typedef int extra_data_t;
using extra_data_t = int;

template<int nDims, typename T = int>
struct Vec {
    extra_data_t extra_data;

    array<T, nDims> values;


    template<typename... Ts>
    Vec(Ts... values) : extra_data{nDims}, values{values...}
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

    auto vec_array = array<void*, 2>{ &v1, &v2 };

    for(int i=0; i<2; ++i) {
        auto nDims = ((int*)vec_array[i])[0];
        if(nDims == 2)
            ((Vec<2>*)vec_array[i])->print(); // (*((Vec<2>*)vec_array[i])).print();
        else if(nDims == 3)
            ((Vec<3>*)vec_array[i])->print();
    }

    return 0;
}
