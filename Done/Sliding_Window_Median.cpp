#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    multiset<int> lo, hi;

    auto balance = [&]() {
        while (lo.size() + 1 > hi.size()) {
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        while (hi.size() > lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };

    // Build the first window
    for (int i = 0; i < k; ++i) {
        lo.insert(arr[i]);
        balance();
    }

    cout << *lo.rbegin();

    for (int i = k; i < n; ++i) {
        // Remove outgoing element
        if (lo.find(arr[i - k]) != lo.end()) {
            lo.erase(lo.find(arr[i - k]));
        } else {
            hi.erase(hi.find(arr[i - k]));
        }
        // Insert incoming element
        lo.insert(arr[i]);
        balance();
        cout << " " << *lo.rbegin();
    }
    cout << "\n";
    return 0;
}
