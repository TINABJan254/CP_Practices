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

void solve(){
	int n, k; cin >> n >> k;
	map<int, int> firstPos, lastPos;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		if (firstPos.find(x) == firstPos.end())
			firstPos[x] = i;
		lastPos[x] = i;
	}

	while (k--){
		int x, y; cin >> x >> y;
		if (firstPos.find(x) != firstPos.end() 
			&& lastPos.find(y) != lastPos.end()
			&& firstPos[x] <= lastPos[y])
				cout << "YES\n";
		else
			cout << "NO\n";
	}
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
https://codeforces.com/problemset/problem/1702/C
Muốn đi từ trạm x - y
Ta luôn kiểm tra trạm x xuất hiện đầu tiên và trạm y xuất hiện cuối cùng
	vd: 3 1 3 5 9
		0 1 2 3 4
		từ 3 - 1
			nếu ta xét trạm 3 ở vị trí 2 sẽ ko được => cần xét trạm 3 ở vị trí 0
=> đi tìm vị trí xuất hiện đầu tiên và cuối cùng của trạm
*/