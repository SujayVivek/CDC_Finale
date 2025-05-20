#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    int num = 0;
    int top = 0,bottom =n-1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = right; i >= left; --i)
            grid[top][i] = num++;
        ++top;
        for (int i = top; i <= bottom; ++i)
            grid[i][left] = num++;
        ++left;
        if (top <= bottom) {
            for (int i = left; i <= right; ++i)
                grid[bottom][i] = num++;
            --bottom;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                grid[i][right] = num++;
            --right;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            grid[i][j] = n*n-1-grid[i][j];
    for (auto &row : grid) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}