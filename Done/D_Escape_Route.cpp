#include <bits/stdc++.h>
using namespace std;

#define int long long
int H, W;
vector<string> grid;
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1};
char dirChar[] = {'^', '>', 'v', '<'};

bool inBounds(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}
void Solve() {
    cin >> H >> W;
    grid.resize(H);
    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    vector<vector<char>> arrow(H, vector<char>(W, '#'));
    queue<tuple<int, int, int>> q; 

    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'E') {
                dist[i][j] = 0;
                arrow[i][j] = 'E';
                q.push({i, j, -1}); 
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, dirFromParent] = q.front(); q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!inBounds(nx, ny)) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                arrow[nx][ny] = dirChar[(d + 2) % 4]; 
                q.push({nx, ny, d});
            }
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << arrow[i][j];
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
