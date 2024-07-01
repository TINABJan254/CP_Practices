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
	int w[n + 5];
	for (int i = 0; i < n; i++)
		cin >> w[i];
	int i = 0, j = n - 1;
	int res = 0;
	pii A, B;
	//first:  total weight
	//second: total candies
	A.fi = 0; A.se = 0;
	B.fi = 0; B.se = 0;
	while (i <= j){
		if (A.fi < B.fi){
			A.fi += w[i++];
			++A.se;
		}
		else if (A.fi > B.fi){
			B.fi += w[j--];
			++B.se;
		}
		if (A.fi == B.fi){
			res = (A.se + B.se);
			A.fi += w[i++];
			++A.se;
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
https://codeforces.com/problemset/problem/1669/F
*/