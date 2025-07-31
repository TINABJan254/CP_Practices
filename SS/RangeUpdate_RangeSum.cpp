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

ll bit1[N], bit2[N];

void updatePoint(ll *b, int i, ll v) {
    for (; i <= N; i += (i & -i)) b[i] += v;
}

void updateRange(int l, int r, ll v) {
    updatePoint(bit1, l, v);
    updatePoint(bit1, r+1, -v);
    updatePoint(bit2, l, v*(l-1)); // Bù vào
    updatePoint(bit2, r+1, -v*r); // Khi cộng dồn sẽ bị thừa đi r lần v => trừ đi
}

ll getSum(ll *b, int i) {
    ll ans = 0;
    for (; i; i -= (i & -i)) ans += b[i];
    return ans;
}

ll prefixSum(int i){
    return getSum(bit1, i)*i - getSum(bit2, i);
}

ll rangeSum(int l, int r) {
    return prefixSum(r) - prefixSum(l-1);
}

void solve(){
    int n, q; cin >> n >> q;
    int a[n + 5] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        updateRange(i, i, a[i]);
    }

    while (q--){
        int x; cin >> x;
        if (x == 1) {
            int l, r, v; cin >> l >> r >> v;
            updateRange(l, r, v);
        } else {
            int l, r; cin >> l >> r;
            cout << rangeSum(l, r) << EL;
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
    // cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*

*/
