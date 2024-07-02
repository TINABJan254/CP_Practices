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
	ll d[2][50];
	memset(d, 0, sizeof(d));
	map<string, ll> mp;
	ll res = 0;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		/*
		trước đó cứ có xâu nào có đầu/cuối giống đầu/cuối của xâu s thì
		sẽ tạo thành 1 cặp với xâu s, tuy nhiên, vì trước đó có thể
		có xâu = xâu s (tức cả đầu lẫn cuối đều giống s) thì sẽ phải trừ đi
		số lượng xâu s đã xuất hiện ở trước * 2 (nhân 2 bởi vì một xâu s sẽ
		cho ra 2 xâu, 1 xâu đầu giống s, 1 xâu cuối giống s)
		*/
		res += d[0][s[0] - 'a'] + d[1][s[1] - 'a'] - 2*mp[s];
		d[0][s[0] - 'a']++; //xâu bắt đầu với s[0]
		d[1][s[1] - 'a']++; //xâu kết thúc với s[1]
		mp[s]++; //tăng số lượng xâu s xuất hiện
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
https://codeforces.com/problemset/problem/1669/E
*/