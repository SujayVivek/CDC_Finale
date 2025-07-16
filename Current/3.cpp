#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, N;
    cin >> X >> N;

    vector<int> pages(N);
    for(int i = 0; i < N; i++){
        cin >> pages[i];
    }

    list<int> cache;                              // front = MRU, back = LRU
    unordered_map<int, list<int>::iterator> mp;   // page -> its position in the list
    int hits = 0;

    for(int i = 0; i < N; i++){
        int p = pages[i];
        auto it = mp.find(p);
        if(it != mp.end()){
            // HIT: move this page to front
            cache.erase(it->second);
            cache.push_front(p);
            mp[p] = cache.begin();
            hits++;
        } else {
            // MISS: if full, evict LRU
            if((int)cache.size() == X){
                int lru = cache.back();
                cache.pop_back();
                mp.erase(lru);
            }
            // insert new page at front
            cache.push_front(p);
            mp[p] = cache.begin();
        }

        // print cache state after this request
        int printed = 0;
        for(auto lit = cache.begin(); lit != cache.end() && printed < X; ++lit, ++printed){
            cout << *lit;
            if(printed + 1 < X) cout << ' ';
        }
        // pad with zeros if cache has fewer than X pages
        while(printed < X){
            if(printed > 0) cout << ' ';
            cout << 0;
            printed++;
        }
        cout << "\n";
    }

    // compute hit percentage (floor) and print
    int percent = (hits * 100) / N;
    cout << percent << "\n";

    return 0;
}
