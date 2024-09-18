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
int a[4005][4005];
vector<pii> e; //edge List
int degree[4005];

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
		degree[x]++;
		degree[y]++;
		e.pb({x, y});
	}

	int sum = INT_MAX;
	for (auto p : e){
		int x = p.fi;
		int y = p.se;
		for (int k = 1; k <= n; k++){
			if (a[x][k] && a[y][k]){
				sum = min(sum, degree[x] + degree[y] + degree[k]);
			}
		}
	}
	if (sum == INT_MAX)
		cout << "-1";
	else
		cout << sum - 6 << EL;

}

int main(){
	faster();
	solve();
	return 0;
}

/*
Thay vì duyệt all bộ 3 {x, y, k} mất O(n^3) ta sẽ đi làm cách sau:
	  Sử dụng ma trận kề có cạnh x,y thì a[x][y] = a[y][x] = 1;
	  (x, y, k) là bộ 3 thỏa mãn nếu: a[x][y] = a[x][k] = a[y][k] = 1;
	  Ta sẽ lợi dụng danh sách cạnh đề đã cho, bởi vì nếu có cạnh (x, y) thì 
	chắc chắn sẽ có đường đi từ x->y hay a[x][y] = 1;
	  Vậy nên khi ta duyệt danh sách cạnh, ta đã bỏ qua được rất nhiều cặp
	x, y không đường đi tới nhau, khi đã có cặp x, y rồi, công  việc bây giờ 
	đi tìm người thứ 3, người thứ 3 chỉ cần duyệt từ 1->n sao cho a[x][k] = a[y][k] = 1
	  Sự nổi tiếng của mỗi người chính là bậc của đỉnh đó, theo đề bài thì 
	trong sự nổi tiếng ko tính quan hệ giữa 3 chàng lính => cần trừ đi quan hệ giữa 3 người
	với nhau, mà mỗi chàng lính sẽ có 2 quan hệ với 2 người còn lại => 3 người sẽ có 6 quan
	hệ vậy kết quả phải trừ đi 6
https://codeforces.com/contest/574/problem/B
*/