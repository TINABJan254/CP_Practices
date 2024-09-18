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
bool visited[100005];


void solve(){
	cin >> n >> m;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1);//start at 1
	visited[1] = true;
	while (!pq.empty()){
		int u = pq.top(); pq.pop();
		cout << u << ' ';
		for (auto v : adj[u]){
			if (!visited[v]){
				pq.push(v);
				visited[v] = true;
			}
		}
	}
	cout << EL;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
https://codeforces.com/problemset/problem/1106/D
Vì các đỉnh có thể đi lại nhiền lần, nên kề của đỉnh con cũng là
kề của đỉnh cha:
	vd: u->(v, o, i), mà v->(e, f, g, h) => u -> (v, e, f, g, h, o, i)
Cho nên tại mỗi bước ta cần xem đi đến đỉnh nào nhỏ nhất thì đi, vì có thể đi
lại các đỉnh đã qua
Ta sẽ dùng priority_queue
*/