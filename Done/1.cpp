#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<vector<int>> a(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int gossipers = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 1) {
                bool canGossip = false;
                if (i > 0        && a[i - 1][j] == 1) canGossip = true;
                if (i + 1 < M    && a[i + 1][j] == 1) canGossip = true;
                if (j > 0        && a[i][j - 1] == 1) canGossip = true;
                if (j + 1 < N    && a[i][j + 1] == 1) canGossip = true;
                if (canGossip) gossipers++;
            }
        }
    }

    cout << gossipers << "\n";
    return 0;
}
