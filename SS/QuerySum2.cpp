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

ll BIT[N];

void update(int i, int v) {
	for (; i <= N; i += (i & -i)) BIT[i] += v;
}

ll get(int i) {
	ll ans = 0;
	for (; i; i -= (i & -i)) ans += BIT[i];
	return ans;
}

void solve(){
    int n, q; cin >> n >> q;
    int a[n+5] = {0}, diff[n+5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) diff[i] = a[i] - a[i-1];
    for (int i = 1; i <= n; i++) update(i, diff[i]);

    while (q--) {
    	int x; cin >> x;
    	if (x == 1) {
    		int l, r, v; cin >> l >> r >> v;
    		update(l, v);
    		update(r + 1, -v);
    	} else {
    		int l, r; cin >> l >> r;
    		cout << get(r) - get(l-1) << EL;
    	}
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
    while (TC--){
      solve();
    }
    return 0;
}
/*
    
*/