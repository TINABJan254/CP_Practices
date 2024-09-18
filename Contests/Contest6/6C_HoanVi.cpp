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
	vector<int> v; 
	for (int i = 0; i < n; i++){
		int tmp; cin >> tmp;
		v.pb(tmp);
	}
	int res = 0;
	int minE = v[0];
	for (int i = 0; i < n; i++){
		if (v[i] <= minE){
			++res;
			minE = v[i];
		}
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