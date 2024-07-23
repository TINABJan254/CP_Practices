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
	map<string, int> mp;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		string x; cin >> x;
		mp[x] = ++cnt;
	}

	for (int i = 0; i < m; i++){   
		string vao, ra;
		cin >> vao >> ra;
		if (abs(mp[vao] - mp[ra]) > 1)
			cout << abs(mp[vao] - mp[ra]) - 1 << EL;
		else
			cout << "0\n";
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/