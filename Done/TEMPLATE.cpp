#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool isPrime(int x){
    if(x<2) return false;
    for(int i = 2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}

vector<int> Divisors(int x){ //list of divisors
    vector<int> divs;
    for(int i = 1; i*i<=x; i++){
        if(x%i==0)divs.push_back(i);

        if(i*i!=x){
            divs.push_back(x/i);
        }
    }
    return divs;
}

vector<pair<int,int>> Factors(int x){ //2^5 . 3^4 . 5^1 form
    vector<pair<int,int>>facts;
    for(int i = 2; i*i<=x; i++){
        if(x%i==0){
            int cnt = 0;
            while(x%i==0){
                cnt++; x/=i;
            }
            facts.push_back({i, cnt});
        }
    }
    if(x>1) facts.push_back({x, 1});
}

vector<int> sieve(int N){ //T.C => O(N*log(log(N))) 
    vector<int> is_Prime(N+1, 1);
    is_Prime[1] = 0
    for(int i = 2; i<=N; i++){
        if(is_Prime[i]){
            for(int j = i*i; j<=N; j++){
                isPrime[j] = 0;
            }
        }
    }
}

//To find the sieve in a range of numbers between a and b. What if a = 10^12, and b = 5*(10^12). So we cant use normal sieve
vector<int> rangeSeive(int a, int b){
    //First we find all the primes upto sqrt(b) using normal Sieve, and put all the prime numbers in a Set
    vector<int> primes = sieve(sqrt(b));
    set<int> Pr; 
    for(int i = 0; i<primes.size(); i++) if(primes[i]) set.insert(i);
    
    vector<int> ans(b-a+1, 1); //we will return this range Seive between 'a' and 'b'
    //now we iterate through the set, and find the multiple of the prime that is greater than 'a' and less than 'b'
    for(int prime: Pr){
        int mul = ((a+prime-1)/prime); 
        
        int fir = mul*prime; //this is the first prime above 'a'
        while(fir<=b){
            ans[fir-a] = 0;
            fir+= prime;
        }
    }
    return ans;
}

class FastFactorization{ //finding factors of a range of numbers. TC- O(N*log(log(N)))
    vector<int> sp; //stores the smallest prime factor

    FastFactorization(int N){
        sp.assign(N+1, 0);
    }
    void createSparringArray(int N){
        for(int i = 2; i<=N; i++){
            sp[i] = i;
        }
        for(int i = 2; i<=N; i++){
            if(sp[i]==i){ //then its a prime
                for(int j = 2*i; j<=N; j++){
                    sp[j] = i;
                }
            }
        }
    }

    vector<int> primeFact(int x){
        vector<int> ans;
        while(x>1){
            ans.push_back(sp[x]);
            x/=sp[x];
        }
        return ans;//all prime factors of x, but no powers
    }
};
void Solve() {
    ios_base: sync_with_stdio(false)
    cin.tie(NULL)

    freeopen("speed.in", "r", stdin)
    freeopen("speed.out", "w", stdout)
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}