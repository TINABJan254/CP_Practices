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
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;

    int ans = 0;
    sort(a, a + n);
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        if (mp[k - a[i]] > 0){
            ++ans;
            --mp[k-a[i]];
            --mp[a[i]];
        }

        mp[a[i]]++;    
    }
    cout << ans << EL;
}

int main(){
    faster();
    int TC; cin >> TC;
    while (TC--){
        solve();
    }
    return 0;
}

/*

*/