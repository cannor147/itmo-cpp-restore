#include <iostream>
#include "set_restore_guard.h"

using namespace std;

template <typename T>
void test(T &x, T const &new_value) {
    cout << "before: " << x << endl;
    set_restore_guard<T> g(x, new_value);
    cout << "now: " << x << endl;
    g.restore();
    cout << "after: " << x << endl;
    cout << endl;
}

int main() {
    std::cout << "Hello, World! This is my test for set_restore_guard<T>" << std::endl;
    cout << endl;

    int x = -1;
    test<int>(x, 42);

    double y = 0.73;
    test<double>(y, 1.19283);

    string z = "text";
    test<string>(z, "kek");
    return 0;
}