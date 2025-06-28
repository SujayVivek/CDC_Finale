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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> pref(N);
    int sum = 0;
    int last_bad = -1;
    for (int i = 0; i < N; ++i) {
        sum = (sum + A[i]) % 3;
        if (sum == 0) last_bad = i;
        pref[i] = sum;
    }
    if (last_bad == -1) {
        cout << "Yes" << endl;
        return;
    }
    if(last_bad==N-1){
        cout<<"No"<<endl; return;
    }
    sum = 0;
    // cout<<last_bad<<endl;
    for(int i = last_bad + 1; i>=0; i--){
        sum+= A[i];
        if(sum%3==0){
            cout<<"No"<<endl;
        }
    }
    for(int i = last_bad + 2; i<N; i++){
        sum+= A[i];
        if(sum%3==0){
            cout<<"No"<<endl; return;
        }
    }
    cout<<"Yes"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}