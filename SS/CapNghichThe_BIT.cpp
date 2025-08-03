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

int bit[N];

void update(int i, int v) {
    for (; i <= N; i += (i & -i)) bit[i] += v;
}

int get(int i) {
    int ans = 0;
    for (; i; i -= (i & -i)) ans += bit[i];
    return ans;
}

void solve(){
    memset(bit, 0, sizeof(bit));

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int f = get(a[i] - 1);
        ans += f;
        update(a[i], 1);
    }

    cout << ans << endl;
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
    Cặp nghịch thế sử dụng BIT  
    Tư tưởng giống bruteforce nhưng ta sẽ sử dụng BIT để tối ưu việc cộng dồn
*/