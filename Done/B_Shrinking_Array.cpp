#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i + 1 < n; i++) {
        if (llabs(a[i] - a[i+1]) <= 1) {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 0; i<n-1; i++) {
        int L = min(a[i], a[i+1]), R = max(a[i], a[i+1]);
        if (i-1 >= 0) {
            int v = a[i-1];
            if (R>=v-1 && L<=v+1) {
                cout <<1<< endl; return;
            }
        }
        if (i+2 < n) {
            int v = a[i+2];
            if (R >=v-1 && L <=v+1) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout <<-1<< endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}
