#include <iostream>
using namespace std;

void f() {
    long long a, b, c;
    cin >> a >> b >> c;
    if (b < c) {
        long long t = b;
        b = c;
        c = t;
    }
    if (a > b || a < c) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = t; i > 0; --i) {
        f();
    }
    return 0;
}
