#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
vector<string> grid;

void Solve() {
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    vector<vector<char>> best(n, vector<char>(n));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {-1, -1}));

    best[0][0] = grid[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                best[i][j] = min(grid[i][j], (char)(best[i][j-1] + 1 - 1));
                parent[i][j] = {i, j-1};
            } else if (j == 0) {
                best[i][j] = min(grid[i][j], (char)(best[i-1][j] + 1 - 1));
                parent[i][j] = {i-1, j};
            } else {
                if (best[i-1][j] < best[i][j-1]) {
                    best[i][j] = min(grid[i][j], (char)(best[i-1][j] + 1 - 1));
                    parent[i][j] = {i-1, j};
                } else {
                    best[i][j] = min(grid[i][j], (char)(best[i][j-1] + 1 - 1));
                    parent[i][j] = {i, j-1};
                }
            }
        }
    }

    // Reconstruct path
    string result;
    int i = n - 1, j = n - 1;
    while (i != -1 && j != -1) {
        result += grid[i][j];
        tie(i, j) = parent[i][j];
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
