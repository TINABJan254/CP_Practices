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

struct Data{
    multiset<int> ms;
};

Data tree[4*N];
int a[N], n, m;

Data mergeNode(Data& l_node, Data& r_node) {
    Data res;
    res.ms.insert(l_node.ms.begin(), l_node.ms.end());
    res.ms.insert(r_node.ms.begin(), r_node.ms.end());
    return res;
}

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node].ms.insert(a[tl]);
    } else {
        int mid = (tl + tr) / 2;
        build(2*node, tl, mid);
        build(2*node + 1, mid + 1, tr);

        tree[node] = mergeNode(tree[2*node], tree[2*node + 1]);
    }
}

void update(int node, int tl, int tr, int idx, int oldv, int newv) {
    auto it = tree[node].ms.find(oldv);
    if (it != tree[node].ms.end()) {
        tree[node].ms.erase(it);
    }
    tree[node].ms.insert(newv);
    if (tl == tr) {
        return;
    }
    int mid = (tl + tr) / 2;
    if (idx <= mid) {
        update(2*node, tl, mid, idx, oldv, newv);
    } else {
        update(2*node + 1, mid + 1, tr, idx, oldv, newv);
    }
}

int query2(int node, int tl, int tr, int l, int r, int x) {
    if (l > tr || r < tl) return INT_MAX;
    if (l <= tl && tr <= r) {
        auto it = tree[node].ms.upper_bound(x);
        if (it != tree[node].ms.end()) return *it;
        else return INT_MAX;
    }
    int mid = (tl + tr) / 2;
    int left = query2(2 * node, tl, mid, l, r, x);
    int right = query2(2 * node + 1, mid + 1, tr, l, r, x);
    return min(left, right);
}


void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    while (m--) {
        int q; cin >> q;
        if (q == 1){
            int u, val; cin >> u >> val;
            int oldv = a[u];
            update(1, 1, n, u, oldv, val);
            a[u] = val;
        } else {
            int l, r, x; cin >> l >> r >> x;
            int ans = query2(1, 1, n, l, r, x);
            cout << (ans == INT_MAX ? -1 : ans) << endl;
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

/**
 *    author:  thienban
 *    created: 10-08-2025 9:10:49
**/

/*
    
*/