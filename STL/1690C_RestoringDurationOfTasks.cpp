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
	pii a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i].fi;
	for (int i = 0; i < n; i++)
		cin >> a[i].se;
	sort(a, a + n);
	ll res = a[0].se - a[0].fi;
	cout << res << ' ';
	int cur_time = a[0].se;
	for (int i = 1; i < n; i++){
		if (a[i].fi > cur_time){
			res = a[i].se - a[i].fi;
			cur_time = a[i].se;
			cout << res << " ";
		}
		else{
			if (a[i].se > cur_time){
				res = a[i].se - cur_time;
				cur_time = a[i].se;
				cout << res << " ";
			}
		}
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
https://codeforces.com/problemset/problem/1690/C
*/