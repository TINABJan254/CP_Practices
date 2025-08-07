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

int n, a[N];
ll tree[4 * N];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = a[l]; //node la
    } else {
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

// l, r chi so doan ma node hien tai quan ly
// idx chi so can update
void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] += val;
    } else {
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(2*node, l, mid, idx, val);
        } else {
            update(2*node + 1, mid + 1, r, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

ll query(int node, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return 0;
    if (tl >= l && tr <= r) return tree[node];

    int mid = (tl + tr) / 2;
    ll p1 = query(2*node, tl, mid, l, r);
    ll p2 = query(2*node + 1, mid + 1, tr, l, r);

    return p1 + p2;
}

ll query2(int node, int tl, int tr, int l, int r) {
    if (r < l) return 0;
    if (tl == l && tr == r) return tree[node];

    int tmid = (tl + tr) / 2;
    ll p1 = query(2*node, tl, tmid, l, min(r, tmid));
    ll p2 = query(2*node + 1, tmid + 1, tr, max(l, tmid), r);

    return p1 + p2;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    // for (int i = 1; i <= 15; i++) cout << tree[i] << " ";

    int m; cin >> m;
    while (m--) {
        int x; cin >> x;
        if (x == 1) {
            int u, v; cin >> u >> v;
            update(1, 1, n, u, v);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
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