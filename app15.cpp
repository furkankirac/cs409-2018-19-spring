// std::reference_wrapper
// threads --> std::thread: func*, functor, lambda
// tasks --> std::async: future, promise

// structured bindings: pair, map examples

#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

//template<typename T>
//struct ReferenceWrapper
//{
//    T& ref;
//    ReferenceWrapper(T& ref) : ref{ref} { }

//    operator T() const { return ref; }
//};

// ----------------------
int main(int argc, char* argv[])
{
    int k = 10, m = 20;
    auto k_ref = ref(k);
    auto V = vector{ref(k), ref(m)}; // using std::reference_wrapper<int> automatically

//    auto v = vector{1, 2, 3, 4, 5, 6};

    return 0;
}
