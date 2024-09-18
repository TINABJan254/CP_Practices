#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        sum += x;
        int r = (sum % k + k) % k;
        if (mp.count(r)){
            res += mp[r];
        }
        
        mp[r]++;

    }
    cout << res;
}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/