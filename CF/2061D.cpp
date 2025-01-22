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
    int n, m; cin >> n >> m;

    multiset<int> a, b;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert(x);
    }

    for (int i = 0; i < m; i++){
        int x; cin >> x;
        b.insert(x);
    }

    while (!b.empty()) {
        if (b.sz > a.sz){
            cout << "No\n"; return;
        }

        int x = *b.rbegin(); b.erase(b.find(x));

        if (*a.rbegin() == x){
            a.erase(a.find(x));
        } else {
            b.insert(x/2);
            b.insert(x-x/2); //b.insert(x/2 + x%2);
        }
    }

    if (a.sz) cout << "No\n"; else cout << "Yes\n";
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC; cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*

*/