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
#define ALL(t) (t).begin(),(t).end()

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, m;
vector<pii> adj[105];
bool visited[105];

bool DFS(int src, int dst, int col){
	visited[src] = true;
	if (src == dst)
		return true;
	for (auto p : adj[src]){
		if (!visited[p.fi] && p.se == col)
			if (DFS(p.fi, dst, col)) 
				return true;
	}
	return false;
}

void solve(){
	cin >> n >> m;	
	for (int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}

	int q; cin >> q;
	while(q--){
		int u, v; cin >> u >> v;
		int res = 0;
		for (int i = 1; i <= 100; i++){
			memset(visited, false, sizeof(visited));
			if (DFS(u, v, i)) ++res;
		}
		cout << res << EL;
	}

}

int main(){
	faster();
	solve();
	return 0;
}

/*
https://codeforces.com/problemset/problem/505/B
*/