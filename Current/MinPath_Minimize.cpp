#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve() {
    int N;
    cin >> N;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    vector<vector<int>> adj(N+1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> used(N+2);
    for (int i = 1; i <= N; i++)
        if (A[i] > 0)
            used[A[i]] = 1;
    vector<int> pref(N+2), phi(N+2);
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i-1] + used[i];
    for (int k = 1; k <= N + 1; k++)
        phi[k] = (k - 1) - pref[k-1];
    vector<int> caps;
    int zeros = 0;
    for (int v = 1; v <= N; v++) {
        if (A[v] != 0) continue;
        zeros++;
        int maxFixed = 0, zeroDeg = 0;
        for (int u : adj[v]) {
            if (A[u] > 0)
                maxFixed = max(maxFixed, A[u]);
            else
                zeroDeg++;
        }
        if (maxFixed > 0 || zeroDeg > 0)
            caps.push_back(min(N, maxFixed + 1));
    }
    sort(caps.begin(), caps.end());
    int bestFixed = LLONG_MAX;
    for (int v = 1; v <= N; v++) {
        if (A[v] <= 0) continue;
        int i = A[v];
        bool ok = false;
        for (int u : adj[v]) {
            if (A[u] >= i || A[u] == 0) {
                ok = true;
                break;
            }
        }
        if (!ok)
            bestFixed = min(bestFixed, i);
    }
    int answer = N + 1;
    for (int k = 1; k <= N + 1; k++) {
        if (phi[k] > zeros)
            break;
        if (phi[k] == 0) {
            answer = k;
            break;
        }
        bool ok = true;
        for (int j = 0; j < phi[k]; j++) {
            if (caps[caps.size() - 1 - j] < k - 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            answer = k;
            break;
        }
    }
    cout << min(answer, bestFixed) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        Solve();
    return 0;
}
