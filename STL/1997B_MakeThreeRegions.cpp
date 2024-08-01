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
	int res = 0;
	int n; cin >> n;
	string r1, r2; cin >> r1 >> r2;
	for (int i = 1; i < n; i++){
		if (r1[i] == '.' && r2[i-1] == 'x' && r2[i + 1] == 'x' 
			&& r2[i] == '.' && r1[i - 1] == '.' && r1[i + 1] == '.')
				++res;
	}

	for (int i = 1; i < n; i++){
		if (r2[i] == '.' && r1[i-1] == 'x' && r1[i + 1] == 'x' 
			&& r1[i] == '.' && r2[i - 1] == '.' && r2[i + 1] == '.')
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

*/