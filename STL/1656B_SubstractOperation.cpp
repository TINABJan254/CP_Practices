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
	int a[n + 5];
	set<int> SET;
	for (int i = 0; i < n; i++){		
		cin >> a[i];
		SET.insert(a[i]);
	}

	for (int i = 0; i < n; i++){
		if (SET.find(a[i] - k) != SET.end()){
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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
Nhận xét:
	1: sau mỗi bước hiệu các số trong dãy ko thay đổi
	2: tại bước cuối cùng khi chỉ còn 2 số (x, y)
		khi xóa x => số còn lại là y - x
		y - x = k mới thỏa mãn
	=> trong dãy chỉ cần tồn tại cặp số có hiệu = k thì sẽ thỏa mãn

https://codeforces.com/problemset/problem/1656/B
*/