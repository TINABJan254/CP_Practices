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
	string s[n + 5];
	set<string> SET;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		SET.insert(s[i]);
	}

	for (int i = 0; i < n; i++){
		bool flag = false;
		for (int j = 1; j < s[i].sz; j++){
			string L = s[i].substr(0, j);
			string R = s[i].substr(j, s[i].sz - 1);
			if (SET.find(L) != SET.end() && SET.find(R) != SET.end()){
				cout << "1";
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << "0";
	}
	cout << EL;
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
https://codeforces.com/problemset/problem/1703/D
*/