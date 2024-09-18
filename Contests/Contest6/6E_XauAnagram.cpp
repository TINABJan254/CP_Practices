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
	int n; cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; i++){
		string tmp; cin >> tmp;
		sort(tmp.begin(), tmp.end());
		mp[tmp]++;
	}

	ll res = 0;
	for (auto it = mp.begin(); it != mp.end(); it++){
		int fre = it->se;
		res += fre * (fre - 1) / 2;
	}
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/