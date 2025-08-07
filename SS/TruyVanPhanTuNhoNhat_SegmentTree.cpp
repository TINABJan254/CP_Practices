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

int n, m, a[N];
int tree[4 * N];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node] = tl;
    } else {
        int mid = (tl + tr) / 2;
        build(2 * node, tl, mid);
        build(2 * node + 1, mid + 1, tr);

        int idx1 = tree[2 * node];
        int idx2 = tree[2 * node + 1];

        tree[node] = (a[idx1] <= a[idx2]) ? idx1 : idx2;
    }
}

void update(int node, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        a[idx] = val;
        tree[node] = idx;
    } else {
        int mid = (tl + tr) / 2;
        if (idx <= mid) {
            update(2 * node, tl, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, tr, idx, val);
        }

        int idx1 = tree[2 * node];
        int idx2 = tree[2 * node + 1];

        tree[node] = (a[idx1] <= a[idx2]) ? idx1 : idx2;
    }
}

int query(int node, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return 0;

    if (l <= tl && tr <= r) return tree[node];

    int mid = (tl + tr) / 2;
    int p1 = query(2 * node, tl, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, tr, l, r);

    return (a[p1] <= a[p2] ? p1 : p2);
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = INT_MAX;

    build(1, 1, n);
    // for (int i = 1; i <= 9; i++) cout << i << " " << tree[i] << endl;
    // cout << endl;

    while (m--) {
        int x; cin >> x;
        if (x == 1) {
            int u, v; cin >> u >> v;
            update(1, 1, n, u, v);

            // for (int i = 1; i <= 9; i++) cout << i << " " << tree[i] << endl;
            // cout << endl;
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
    Có thể cần so sánh chặt hơn ở phần lựa chọn idx1, idx2 vì người ta yêu cầu
    chọn idx nhỏ nhất, nhưng ở đây lúc đệ quy ta luôn đệ quy bên trái trước nên có thể
    đã đảm bảo idx1 < idx2

    code so sánh kĩ:
    if (a[idx1] < a[idx2]) {
        tree[node] = idx1;
    } else if (a[idx1] > a[idx2]) {
        tree[node] = idx2;
    } else {
        tree[node] = min(idx1, idx2);
    }

*/