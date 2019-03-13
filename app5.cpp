// Vec2d, Vec3d, templates (typename, non-type param)
// CV qualifiers: const, volatile
// const, mutable
// inheritance
// dynamic polymorphism, v-table

#include <iostream>
#include <array>
//#include <algorithm>

using namespace std;

int dot_product_2d(int x1, int y1, int x2, int y2)                  { return x1*x2 + y1*y2; }
int dot_product_3d(int x1, int y1, int z1, int x2, int y2, int z2)  { return x1*x2 + y1*y2 + z1*z2; }

void print_2d(int x, int y) { cout << "[" << x << ", " << y << "]" << endl; }

// ----------------------
struct Vec2d { int x, y; };
struct Vec3d { int x, y, z; };

int dot_product_2d(const Vec2d a, const Vec2d b) { return a.x*b.x + a.y*b.y; }
int dot_product_3d(Vec3d a, Vec3d b) { return a.x*b.x + a.y*b.y + a.z*b.z; }

namespace Better {

    struct Vec2d
    {
        int x, y;
        int dot_product(const Vec2d b) const { return x*b.x + y*b.y; }
        void print() const { }
    };

    struct Vec3d {
        int x, y, z;
        int dot_product(const Vec3d b) const { return x*b.x + y*b.y + z*b.z; }
        void print() const { }
    };

} // namespace Better

namespace EvenBetter {
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


} // namespace EvenBetter



// ----------------------
int main(int argc, char* argv[])
{
    cout << dot_product_2d(10, 20, 5, 3) << endl;
    cout << dot_product_3d(10, 20, 1, 5, 3, 2) << endl;
    print_2d(10, 20);
    cout << "-----" << endl;

    cout << dot_product_2d({10, 20}, {5, 3}) << endl;
    cout << dot_product_3d({10, 20, 1}, {5, 3, 2}) << endl;
    cout << "-----" << endl;

    cout << Better::Vec2d{10, 20}.dot_product({5, 3}) << endl;
    cout << Better::Vec3d{10, 20, 1}.dot_product({5, 3, 2}) << endl;
    cout << "-----" << endl;

    cout << EvenBetter::Vec<2>{10, 20}.dot_product({5, 3}) << endl;
    cout << EvenBetter::Vec<3>{10, 20, 1}.dot_product({5, 3, 2}) << endl;
    cout << "-----" << endl;

    EvenBetter::Vec<3, float>{10.3f, 20.0f, 1.2f}.print();

    return 0;
}
