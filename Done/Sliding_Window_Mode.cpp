#include <bits/stdc++.h>
using namespace std;

// Sliding window mode
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    map<int, int> freq;                  // value -> frequency
    map<int, set<int>> freq_map;         // frequency -> set of values

    // Initialize the first window
    for (int i = 0; i < k; ++i) {
        int val = arr[i];
        int oldf = freq[val];
        if (oldf > 0) freq_map[oldf].erase(val);
        freq[val]++;
        freq_map[oldf + 1].insert(val);
    }

    // Helper to get current mode
    auto get_mode = [&]() -> int {
        auto it = freq_map.rbegin(); // highest frequency
        return *it->second.begin();  // smallest value with that frequency
    };

    cout << get_mode();

    // Slide the window
    for (int i = k; i < n; ++i) {
        int out = arr[i - k], in = arr[i];

        // Remove outgoing
        int oldf_out = freq[out];
        freq_map[oldf_out].erase(out);
        if (freq_map[oldf_out].empty()) freq_map.erase(oldf_out);
        freq[out]--;
        if (freq[out] > 0) freq_map[oldf_out - 1].insert(out);

        // Add incoming
        int oldf_in = freq[in];
        if (oldf_in > 0) freq_map[oldf_in].erase(in);
        freq[in]++;
        freq_map[oldf_in + 1].insert(in);

        cout << " " << get_mode();
    }
    cout << "\n";
    return 0;
}
