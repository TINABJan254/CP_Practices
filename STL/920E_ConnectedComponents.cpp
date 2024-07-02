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
set<int> no_adj[200005];

void solve(){
	 cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		no_adj[x].insert(y);
		no_adj[y].insert(x);
	}
	set<int> s;//để kiểm soát đỉnh nào đã được duyệt
	for (int i = 1; i <= n; i++) s.insert(i);

	vi res;
	for (int i = 1; i <= n; i++){
		//chua duyet i
		if (s.count(i)){
			s.erase(i); //đánh dấu i đã duyệt
			//BFS từ i đến các đỉnh kề với i
			int cnt = 0; //đếm số đỉnh kề với i (hay size của connected component)
			queue<int> q;
			q.push(i);
			while (!q.empty()){
				int u = q.front();
				q.pop();
				++cnt;
				vi ds;
				for (auto v : s)
					if (!no_adj[u].count(v)){
						q.push(v);
						ds.pb(v);//đưa v vào tập đã duyệt
					}
				//đánh dấu tất cả các x đã được duyệt
				for (auto x : ds)
					s.erase(x); 
			}
			res.pb(cnt);
		}
	}
	cout << res.sz << EL;
	sort(res.begin(), res.end());
	for (auto x : res)
		cout << x << ' ';
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Note: ko dùng set để lưu tập kết quả, vì số đỉnh của tplt có thể bằng nhau
https://codeforces.com/problemset/problem/920/E
*/