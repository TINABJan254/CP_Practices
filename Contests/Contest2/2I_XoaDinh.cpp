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
int parent[200005], Sz[200005];
vi adj[200005];
vi d;
bool used[200005];
int cnt;

void make_set(){
	memset(used, false, sizeof(used));
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

void union_sets(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if (x != y){
		if (Sz[x] < Sz[y]) swap(x, y);
		parent[y] = x;
		Sz[x] += Sz[y];
		
		--cnt;
	}
	
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	make_set();

	for (int i = 0; i < n; i++){
		int x; cin >> x;
		d.pb(x);
	}

	cnt = 0;
	vector<string> res;
	for (int i = d.sz - 1; i >= 0; i--){
		int cur = d[i];
		used[cur] = true;
		cnt++;
		for (int x : adj[cur]){
			if (used[x]){
				union_sets(cur, x);
			}
		}

		if (cnt == 1) //đỉnh current cùng tplt với tập tplt hiện có
			res.pb("YES");
		else
			res.pb("NO");
	}

	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size() - 1; ++i)
        cout << res[i] << EL;
    cout << "YES";

}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho đồ thị vô hướng với N đỉnh và M cạnh. Tại mỗi một thời điểm, một đỉnh X 
được lựa chọn để xóa, đồng thời, tất cả các cạnh kết nối với X cũng bị xóa bỏ.

Nhiệm vụ của bạn là hãy xác định xem đồ thị còn lại có liên thông hay không? 
(Tức là tất cả các cặp đỉnh đều có thể kết nối được với nhau).

Input:

Dòng đầu tiên gồm hai số nguyên N và M.

M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u và v mô tả cạnh từ u à v.

N dòng tiếp theo chứa một hoán vị P[] của 1, 2, …, N là thứ tự các đỉnh sẽ bị xóa.

Giới hạn:

2 ≤ N, M ≤ 200 000.

Output: 

In ra N dòng, “YES” nếu đồ thị liên thông, “NO” trong trường hợp ngược lại.

Dòng đầu tiên là kết quả của đồ thị ban đầu. Dòng thứ i+1 thể hiện kết quả của đồ thị còn lại sau khi đỉnh P[i] bị xóa.

Lưu ý: Không in ra kết quả cho đỉnh P[N] vì đồ thị sau cùng là rỗng.

Ví dụ:

Input
4 3
1 2
2 3
3 4
3
4
1
2
Output
YES
NO
YES
YES
*/