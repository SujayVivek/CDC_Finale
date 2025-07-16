#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using u64 = uint64_t;

// --- OrQueue: two-stack queue supporting push, pop, and OR in O(1) amortized ---
struct OrQueue {
    vector<pair<u32,u32>> in, out;
    void push(u32 x) {
        u32 acc = in.empty() ? x : (in.back().second | x);
        in.emplace_back(x, acc);
    }
    void pop() {
        if (out.empty()) {
            while (!in.empty()) {
                u32 v = in.back().first;
                in.pop_back();
                u32 acc = out.empty() ? v : (out.back().second | v);
                out.emplace_back(v, acc);
            }
        }
        out.pop_back();
    }
    u32 get_or() const {
        u32 o1 = in.empty()  ? 0 : in.back().second;
        u32 o2 = out.empty() ? 0 : out.back().second;
        return o1 | o2;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // — Read input parameters —
    int n, k;
    cin >> n >> k;
    u64 x, a, b, c;
    cin >> x >> a >> b >> c;

    OrQueue q;
    u32 answer = 0;

    // — Build sliding windows and accumulate XOR of window ORs —
    for (int i = 0; i < n; ++i) {
        u32 xi = x;
        q.push(xi);
        if (i >= k)        q.pop();
        if (i >= k - 1)    answer ^= q.get_or();
        x = (a * x + b) % c;
    }

    cout << answer << "\n";
    return 0;
}
