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

bool cmp(pii a, pii b){
	return a.fi < b.fi;
}

void solve(){
	int n, x, y; cin >> n >> x >> y;
	pii a[n];
	for (pii &tmp : a) cin >> tmp.fi >> tmp.se;
	sort(a, a + n, cmp);

	int cnt1 = 0, cnt2 = 0; //cnt1: tung, cnt2: truc
	int l = 0, ans = INT_MAX;
	for (int i = 0; i < n; i++){
		if (a[i].se == 1){
			cnt1 += 1;
		} else {
			cnt2 += 1;
		}

		while (cnt1 >= x && cnt2 >= y){
			ans = min(ans, a[i].fi - a[l].fi);
			if (a[l].se == 1) {
				--cnt1;
			} else {
				--cnt2;
			}
			++l;
		}
	}

	if (ans == INT_MAX){
		cout << "-1";
	}
	else {
		cout << ans;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
https://oj.vnoi.info/problem/minroad
*/	