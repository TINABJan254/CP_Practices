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

const ll MOD = 1e9 + 7;
const int N = 1e6 + 5;

ll POW[N], hashT[N];

ll getHashT(int i, int j) {
    return (hashT[j] - hashT[i-1]*POW[j-i+1] + MOD*MOD ) % MOD;
}

void solve(){
    string txt, pat; cin >> txt >> pat;
    int m = txt.sz, n = pat.sz;
    txt = " " + txt; pat = " " + pat;
    POW[0] = 1;
    for (int i = 1; i <= m; i++) POW[i] = (POW[i-1] * 26) % MOD;
    for (int i = 1; i <= m; i++) hashT[i] = (hashT[i-1]*26 + txt[i] - 'a') % MOD;
    ll hashP = 0;
    for (int i = 1; i <= n; i++) hashP = (hashP*26 + pat[i]-'a') % MOD;
    for (int i = 1; i <= m-n+1; i++) 
        if (hashP == getHashT(i, i+n-1)) cout << i << ' ';
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