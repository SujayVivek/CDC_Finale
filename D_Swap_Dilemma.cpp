#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n;
int countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    function<int(int,int)> mergeSort = [&](int l, int r) -> int {
        if (l >= r) return 0;
        int mid = (l + r) / 2;
        int inv = mergeSort(l, mid) + mergeSort(mid + 1, r);
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                inv += (mid - i + 1);
            }
        }
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        for (int x = l; x <= r; x++) arr[x] = temp[x];
        return inv;
    };
    return mergeSort(0, n-1);
}
void Solve() {
    cin>>n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> freq_a, freq_b;
    for (int i = 0; i < n; i++) freq_a[a[i]]++, freq_b[b[i]]++;
    if (freq_a != freq_b) {
        cout << "NO\n";
        return;
    }
    int inv_a = countInversions(a);
    int inv_b = countInversions(b);

    if ((inv_a % 2) == (inv_b % 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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