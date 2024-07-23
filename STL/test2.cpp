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
    int n; cin >> n;
    set<int> a[n + 5];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            int x; cin >> x;
            a[i].insert(x);
        }
    }

    ll chung = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (auto x : a[i]){
                bool ok = false;
                if (a[j].find(x) != a[j].end()){
                    ++chung;
                    break;
                    ok = true;
                }
                if (ok)
                    break;
            }
        }
    }
    ll total = (1ll*n*(n - 1)) / 2;
    ll res = total - chung;
    cout << res << EL;
}

int main(){
	faster();
    solve();
}

/*

*/	