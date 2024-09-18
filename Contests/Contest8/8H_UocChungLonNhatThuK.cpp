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
	int a, b, k; cin >> a >> b >> k;
	for (int i = min(a, b); i >= 1; i--){
		// cout << i << EL;
		if (a % i == 0 && b % i == 0){
			if (k == 1){
				cout << i;
				break;
			}
			else
				--k;
		}
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/