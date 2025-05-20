#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

map<int,int> p1, p2;
void Solve() {
    int n,x;
	cin>>n;
	while(n--){
		string s;
		cin>>s>>x;
		if(s=="+")p1[x]=1;
		else{
			while(p1[p2[x]+x])p2[x]+=x;
			cout<<p2[x]+x<<"\n";
		}
	}
	return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}