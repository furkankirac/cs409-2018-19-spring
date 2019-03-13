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


template<typename T1, typename T2 = T1>
struct Pair : public tuple<T1, T2>
{
    Pair(const T1 val1, const T2 val2) : tuple<T1, T2>{val1, val2}
    {
    }
};

// ----------------------
int main(int argc, char* argv[])
{
    cout << Vec<2>{10, 20}.dot_product({5, 3}) << endl;
    cout << Vec<3>{10, 20, 1}.dot_product({5, 3, 2}) << endl;
    cout << "-----" << endl;

    Vec<3, float>{10.3f, 20.0f, 1.2f}.print();

    const auto v = Vec<3>{10, 20, 30};

    auto p1 = Pair<int, float>{5, 10.0f};
    auto p1b = Pair<int>{5, 20};
    auto p2 = pair<int, float>{5, 10.0f};
    p2.first = 20;
    auto pair_value_first = get<0>(p1);

    auto t1 = tuple<int, int, float, double, char>{10, 20, 0.5f, 23.5, 'f'};
    auto first_value = get<0>(t1); // int
    auto third_value = get<2>(t1); // float
    auto double_value = get<double>(t1); // get the one and only double parameter's value



    return 0;
}
