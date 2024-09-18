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

int f[105][105];

void solve(){
	int n; cin >> n;

	for (int i = 1; i <= n; i++){
		string r; cin >> r;
		for (int j = 0; j < r.sz; j++)
			f[i][j + 1] = r[j] - '0';
		f[i][i] = 1;
	}

	//Floy
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = f[i][j] || (f[i][k] && f[k][j]);

	for (int i = 1; i <= n; i++){
		vi res;
		for (int j = 1; j <= n; j++)
			if (f[j][i]) // Aj la con cua Ai
				res.pb(j);
		cout << res.sz << " ";
		for (int x : res)
			cout << x << " ";
		cout << EL;
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

*/