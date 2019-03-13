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



template<int nDims, typename T = int>
struct Vec {
    int extra_data;

    array<T, nDims> values;

    auto dot_product(const Vec<nDims, T> b) const
    {
        auto sum = T{};
        for(int i=0; i<nDims; ++i)
            sum += values[i]*b.values[i];
        return sum;
    }

    void print() /*const*/
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
    cout << Vec<2>{2, 10, 20}.dot_product({2, 5, 3}) << endl;
    cout << Vec<3>{3, 10, 20, 1}.dot_product({3, 5, 3, 2}) << endl;
    cout << "-----" << endl;


    return 0;
}
