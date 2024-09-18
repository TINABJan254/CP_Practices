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
	int n, q; cin >> n >> q;
	int a[n + 5];
	for (int i = 1; i <= n; i++) cin >> a[i];
	int f1[n + 5] = {0}; //chan
	int f2[n + 5] = {0}; //le
	f1[0] = 1;

	for (int i = 1; i <= n; i++){
		if (a[i] % 2 == 0){
			f1[i] = (f1[i - 1] * 2) % MOD;
			f2[i] = (f2[i - 1] * 2) % MOD;
			/*
			tổng chẵn + số chẵn = tổng chẵn
			tổng chẵn + 0 lấy số đó = tổng chẵn
				=> số cách = số cách chọn tổng chẵn trước đó nhân 2
			
			*/
		}
		else {
			f1[i] = (f1[i - 1] + f2[i - 1]) % MOD;
			f2[i] = (f2[i - 1] + f1[i - 1]) % MOD;

			/*
			tổng lẻ + số lẻ = tổng chẵn
			tổng chẵn + 0 lấy số đó = tổng chẵn
				=> số cách = số cách chọn tổng chẵn + số cách chọn tổng lẻ
			*/
		}
	}

	if (q == 0)
		cout << f1[n];
	else
		cout << f2[n];
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/