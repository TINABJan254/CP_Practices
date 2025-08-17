// TLE
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
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll m = c - b;
    ll maxK = (d - 2) / m;
    ll ans = 0;

    ll r = a % d; //ứng với k = 0;
    for (ll k = 0; k <= maxK; k++) {
        if (r >= 1 && r <= d-1 - m*k) ++ans;
        r = (r + b) % d;
    }

    cout << ans - 1<< endl;
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
    cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}

/*
    
*/