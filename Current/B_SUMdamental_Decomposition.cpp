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
    int n, x; cin>>n>>x;
    int T = __builtin_popcountll(x);
        // cout<<n<<" hi "<<T<<" "<<x<<endl;
        // cout<<__builtin_popcountll(27)<<endl;
    
    if(n==1 && x==0){cout<<-1<<endl; return;}
    if(x==0){
        if(n%2==0) cout<<n<<endl;
        else cout<<n-3+6<<endl;
        return;
    }
    if(T%2){
        if(n%2){
            if(n>T) cout<<n-T+x<<endl;
            else cout<<x<<endl;
        }else{
            if(n>T){
                int p = max(n-T-1, 0ll);
                if(T==1){
                    cout<< x+1 + (x^(x+1)) + p <<endl;
                }else{
                    cout<< x+2 + p<<endl;
                }
            }else{
                cout<<x<<endl;
            }
        }
    }else{
        // cout<<"HI"<<endl;
        if(n%2){
            // cout<<n<<" "<<T<<endl;
            if(n>T){
                int p = max(n-T-1, 0ll);
                if(T==1){
                    cout<< x+1 + (x^(x+1)) + p <<endl;
                }else{
                    cout<< x+2 + p<<endl;
                }
            }else{
                cout<<x<<endl;
            }
        }else{
            if(n>T) cout<<x + n-T<<endl;
            else cout<<x<<endl;
        }
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