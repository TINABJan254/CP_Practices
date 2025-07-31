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
    int n; cin >> n;
    int a[n + 5] = {0}, diff[n + 5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) diff[i] = a[i] - a[i-1];
    for (int i = 1; i <= n; i++) update(i, diff[i]); 

    int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (x == 1) {
			int l, r, v; cin >> l >> r >> v;
			update(l, v);
			update(r + 1, -v);
		} else {
			int p; cin >> p;
			cout << get(p) << EL;
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
	Có 2 loại truy vấn:
		Q1: u, v, val   -> tăng giá trị a[u],...,a[v] thêm bằng val
		Q2: p 			-> tính giá trị tại a[p]

	Ý tưởng:
		Sử dụng mảng hiệu
		Xây dựng mảng diff (diff[i] = a[i]-a[i-1]) (đóng vai trò là mảng A trong bài 1)
		Coi mảng A là preSum[] hay cây BIT (vai trò ở bài 1)
		Q1: update(u, val) và update(v+1, -val)
		Q2: a[u] = getSum(diff[1]+...+diff[u]) = get(u)

		a[1] = diff[1]
		a[2] = diff[1] + diff[2]
		...
		a[i] = diff[1] +...+ diff[i]

		sum[1] = diff[1]
		sum[2] = a[1] + a[2] = diff[1] + (diff[1] + diff[2]) = 2.diff[1] + diff[2]
		..tương tự..
		sum[i] = i*diff[1] + (i-1)*diff[2] + ... + diff[i]

		Muốn mỗi diff[i] luôn nhân với một hệ số cố định, không phụ thuộc vào chỉ số truy vấn
		=> cố định diff[i] nhân với hệ số n-i+1
*/		