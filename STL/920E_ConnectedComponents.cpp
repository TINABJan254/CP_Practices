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

int n, m;
vi adj[200005];
int parent[200005], Sz[200005];

void make_set(){
	for (int i = 1; i <= n; i++){
		parent[i] = i;
		Sz[i] = 1;
	}
}

int find_set(int u){
	if (u == parent[u])
		return u;
	return parent[u] = find_set(parent[u]);
}

bool union_sets(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if (x != y){
		if (Sz[x] < Sz[y]) swap(x, y);
		parent[y] = x;
		Sz[x] += Sz[y];
		return true;	
	}
	return false;
}

void solve(){
	cin >> n >> m;
	bool a[n + 5][n + 5];
	memset(a, true, sizeof(a));
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		a[x][y] = false;
		a[y][x] = false;
	}

	make_set();
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++)
			if (a[i][j] && i != j){
				bool x = union_sets(i, j);
				a[i][j] = a[j][i] = false;
			}
	}

	vi res;
	for (int i = 1; i <= n; i++){
		if (i == parent[i]){
			res.pb(Sz[i]);
		}
	}
	sort(res.begin(), res.end());
	cout << res.sz << EL;
	for (auto x : res)
		cout << x << ' ';
}

int main(){
	faster();
	solve();
	return 0;
}

/*
https://codeforces.com/problemset/problem/920/E
*/