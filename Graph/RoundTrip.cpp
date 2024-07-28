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
vi adj[100005];
bool visited[1000005];
int parent[100005];

void DFS(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if (visited[v]){
			if (v != parent[u]){
				vi path;
				path.pb(v);
				while (u != v){
					path.pb(u);
					u = parent[u];
				}
				path.pb(u);
				reverse(path.begin(), path.end());
				cout << path.sz << EL;
				for (int tmp : path)
					cout << tmp << " ";
				exit(0);
			}
		}
		else {
			parent[v] = u;
			DFS(v);
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	for (int i = 1; i <= n; i++){
		if (!visited[i])
			DFS(i);
	}
	cout << "IMPOSSIBLE";
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/
