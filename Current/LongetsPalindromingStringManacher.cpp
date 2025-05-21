#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

string longestPalindrome(string s) {
    string s_prime = "#";
    for (char c : s) {
        s_prime += c;
        s_prime += "#";        
    }
    int n = s_prime.size();

    vector<int> palindrome_radii(n, 0);
    int center = 0, right = 0;    

    for (int i = 0; i < n; ++i) {
        int mirror = 2*center - i;
        if (i < right)
            palindrome_radii[i] = min(right - i, palindrome_radii[mirror]);

        // expand around i
        while (i - 1 - palindrome_radii[i] >= 0
            && i + 1 + palindrome_radii[i] < n
            && s_prime[i-1-palindrome_radii[i]] == s_prime[i+1+palindrome_radii[i]])
        {
            palindrome_radii[i]++;
        }

        // update center/right
        if (i + palindrome_radii[i] > right) {
            center = i;
            right  = i + palindrome_radii[i];
        }
    }

    int max_len = 0, center_index = 0;
    for (int i = 0; i < n; ++i) {
        if (palindrome_radii[i] > max_len) {
            max_len = palindrome_radii[i];
            center_index = i;
        }
    }

    int start = (center_index - max_len) / 2;
    string longest_palindrome = s.substr(start, max_len);

    return longest_palindrome;   
}

void Solve() {
    int n; cin>>n;
    string s; cin>>s;
    string p = longestPalindrome(s);
    cout<<p.length()<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}