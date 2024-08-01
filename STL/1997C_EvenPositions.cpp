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
	ll res = 0;
	stack<int> st;
	for (int i = 1; i <= n; i++){
		char x; cin >> x;
		if (st.empty()){
			st.push(i);
		}
		else{
			if (x == ')' || x == '_'){
				res += 1ll*(i - st.top());
				st.pop();
			}
			else
				st.push(i);
		}
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