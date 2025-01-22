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

bool cmp(pair<vi, int> a, pair<vi, int> b){
    return a.fi[0] < b.fi[0];
}

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<vi, int>> a;
    for (int i = 0; i < n; i++){
        vi tmp;
        for (int j = 0; j < m; j++){
            int x; cin >> x;
            tmp.pb(x);
        }
        sort(tmp.begin(), tmp.end());
        a.pb({tmp, i + 1});
    }

    sort(a.begin(), a.end(), cmp);
    // for (auto x : a){
    //     for (auto y : x.fi) cout << y << ' ';
    //     cout << " - " << x.se << EL;

    // }

    vi res;
    int ok = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i].fi[j] != (a[i-1].fi[j] + 1)){
                ok = 0;
            }
        }
    }
    
    if (ok){
        for (auto x : a){
            cout << x.se << ' ';
        }
        cout << EL;
    } else {
        cout << "-1\n";
    }
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