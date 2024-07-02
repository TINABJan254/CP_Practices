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
	map<int, int> mp;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		mp[x]++;
	}
	vector<int> v;
	for (auto it = mp.begin(); it != mp.end(); it++)
		if (it->se >= k)
			v.pb(it->fi);

	if (!v.empty()){
		tuple<int, int, int> res;
		res = {1, v[0], v[0]};
		int cnt = 1;
		for (int i = 1; i < v.sz; i++){
			if (v[i] == v[i - 1] + 1){
				++cnt;
				if (cnt > get<0>(res))
					res = {cnt, v[i] - cnt + 1, v[i]};
			}
			else
				cnt = 1;
		}

		cout << get<1>(res) << ' ' << get<2>(res) << EL;
	}
	else{
		//Không có ptử nào xuất hiện >= k lần
		cout << "-1\n";
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
https://codeforces.com/problemset/problem/1676/F
*/