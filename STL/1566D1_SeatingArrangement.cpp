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
	int n, m; cin >> n >> m;
	int a[m + 5];
	int res = 0;
	for (int i = 0; i < m; i++)
		cin >> a[i];	
	for (int i = 0; i < m; i++){
		for (int j = 0; j <= i - 1; j++)
			if (a[j] < a[i])
				++res;
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
https://codeforces.com/problemset/problem/1566/D1
Cái dễ ở đây là n = 1, nên luôn chỉ có 1 hàng ghế
Ta có ai (khả năng nhìn) càng nhỏ thì phải đặt ở vị trí càng nhỏ
=> ta chỉ cần đi đặt lần lượt các người từ người thứ 1 -> n
Với mỗi người thứ i, có khả năng nhìn ai => những người từ thứ j = (1->i-1) 
người nào mà có aj < ai (khả năng nhìn nhỏ hơn người thứ i) thì sẽ phải ngồi
trước i vậy nên người thứ i sẽ phải đi qua mặt những người đó 
=> bài toán đặt ra là kiểm tra các ptử j trước ptử i có aj < ai
*/