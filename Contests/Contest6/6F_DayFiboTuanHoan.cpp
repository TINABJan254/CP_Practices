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
	int b; cin >> b;
	int f1 = 0, f2 = 1;
	int cnt = 1;
	while (true){
		int tmp = (f1 + f2) % b;
		f1 = f2;
		f2 = tmp;
		if (f1 == 0 && f2 == 1){
			cout << cnt << EL;
			return;
		}
		++cnt;
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

*/