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
vi adj[105];
bool visited[105];
int cnt1, cnt2;

void DFS(int u, int pr){
	visited[u] = true;
	++cnt1;
	for (int v : adj[u]){
		if (!visited[v])
			DFS(v, u);
		else{
			if (v != pr){
				++cnt2;
			}
			if (cnt2 > 2)
				return;
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

	cnt1 = 0; //đếm số đỉnh được duyệt
	cnt2 = 0; //đếm số chu trình
	DFS(1, 0);
	if (cnt2 == 2 && cnt1 == n && n == m){ //vì 1 chu trình được đếm 2 lần nên cnt2 = 2
		cout << "FHTAGN!";
	}
	else
		cout << "NO";

}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/