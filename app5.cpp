// Vec2d, Vec3d, templates (typename, non-type param)
// CV qualifiers: const, volatile
// const, mutable
// inheritance
// dynamic polymorphism, v-table

#include <iostream>

using namespace std;

int dot_product_2d(int x1, int y1, int x2, int y2)                  { return x1*x2 + y1*y2; }
int dot_product_3d(int x1, int y1, int z1, int x2, int y2, int z2)  { return x1*x2 + y1*y2 + z1*z2; }

void print_2d(int x, int y) { cout << "[" << x << ", " << y << "]" << endl; }

// ----------------------
struct Vec2d {
    int x, y;
};

int dot_product_2d(Vec2d a, Vec2d b) { return a.x*b.x + a.y*b.y; }

struct Vec3d {
    int x, y, z;
};

int dot_product_3d(Vec3d a, Vec3d b) { return a.x*b.x + a.y*b.y + a.z*b.z; }


// ----------------------
int main(int argc, char* argv[])
{
    cout << dot_product_2d(10, 20, 5, 3) << endl;
    cout << dot_product_3d(10, 20, 1, 5, 3, 2) << endl;
    print_2d(10, 20);

    cout << dot_product_2d(Vec2d{10, 20}, Vec2d{5, 3}) << endl;
    cout << dot_product_3d(Vec3d{10, 20, 1}, Vec3d{5, 3, 2}) << endl;


    return 0;
}
