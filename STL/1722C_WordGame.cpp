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
	vector<string> v1, v2, v3;
	map<string, int> mp;
	for (int i = 0; i < n; i++){
		string x; cin >> x;
		v1.pb(x);
		mp[x]++;
	}
	for (int i = 0; i < n; i++){
		string x; cin >> x;
		v2.pb(x);
		mp[x]++;
	}
	for (int i = 0; i < n; i++){
		string x; cin >> x;
		v3.pb(x);
		mp[x]++;
	}

	ll res = 0;
	for (auto x : v1){
		if (mp[x] == 1)
			res += 3;
		else if (mp[x] == 2)
			res += 1;
	}
	cout << res << ' ';
	res = 0;
	for (auto x : v2){
		if (mp[x] == 1)
			res += 3;
		else if (mp[x] == 2)
			res += 1;
	}
	cout << res << ' ';
	res = 0;
	for (auto x : v3){
		if (mp[x] == 1)
			res += 3;
		else if (mp[x] == 2)
			res += 1;
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
https://codeforces.com/problemset/problem/1722/C
*/