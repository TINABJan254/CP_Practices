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

int f(int x){
	int cnt = 0;
	while (x != 0){
		++cnt;
		x /= 10;
	}

	return cnt;
}

void solve(){
	int n; cin >> n;
	priority_queue<int> q1, q2;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		q1.push(x);
	}
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		q2.push(x);
	}

	int res = 0;
	while (!q1.empty() && !q2.empty()){
		int x1 = q1.top();
		int x2 = q2.top();
		if (x1 == x2){
			q1.pop();
			q2.pop();
		}
		else if (x1 < x2){
			q2.pop();
			q2.push(f(x2));
			++res;
		}
		else{
			q1.pop();
			q1.push(f(x1));
			++res;
		}
	}

	cout << res << EL;
}

int main(){
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
https://codeforces.com/problemset/problem/1728/C
Mỗi bước hãy tìm 2 ptử bằng nhau ở 2 mảng và xóa đi
Nếu ko thấy hãy tìm ptử lớn hơn và thay nó bằng f(nó)
Đẩy 2 mảng vào 2 priority_queue để luôn chọn được ptử lớn nhất
*/