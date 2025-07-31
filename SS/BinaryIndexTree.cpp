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

void update(int u, int v) {
    int idx = u;
    while (idx < N) {
        BIT[idx] += v;
        idx += (idx & (-idx));
    }    
}

ll getSum(int p) {
    ll idx = p, ans = 0;
    while (idx > 0) {
        ans += BIT[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

//Viet ngan gon hon
void update2(int i, int v) {
    for (; i < N; i += (i & -i)) BIT[i] += v;
}

//Viet ngan gon hon
ll getSum2(int i) {
    ll ans = 0;
    for (; i; i -= (i & -i)) ans += BIT[i];
    return ans;
}

void solve(){
    int n; cin >> n;
    int a[n+5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) update(i, a[i]);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int cmd, u, v;
        ll val;
        cin >> cmd;
        if (cmd == 1) {
            cin >> u >> val;
            update(u, val);
        } else {
            cin >> u >> v;
            cout << getSum(v) - getSum(u - 1) << EL;
        }
    }
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        freopen("../build/outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC; 
    TC = 1;
    while (TC--){
      solve();
    }

    return 0;
}
/*
    Có 2 loại truy vấn:
        Q1: u, val   -> tăng giá trị a[u] thêm bằng val
        Q2: u, v     -> tính giá trị tại a[u]+...+a[v];

    Ý tưởng:
        Sử dụng tính chất mảng cộng dồn 
*/