#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> b;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            b.push_back(a[i]);
        } else {
            b.push_front(a[i]);
        }
    }

    if (b.size() % 2 == 0){
        for (auto x : b) cout << x << " ";
    } else {
        for (auto it = b.rbegin(); it != b.rend(); ++it) cout << *it << " ";
    }
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC = 1; 
    // cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
    
*/