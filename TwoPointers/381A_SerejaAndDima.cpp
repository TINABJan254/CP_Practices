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
	int a[n];
	for (int &x : a) cin >> x;

	int l = 0, r = n - 1;
	int p1 = 0, p2 = 0;
	int turn = 0; //0: Sereja, 1: Dima
	while (l <= r){
		if (a[l] > a[r]){
			if (turn == 0) 
				p1 += a[l++];
			else 
				p2 += a[l++];
		}
		else {
			if (turn == 0)
				p1 += a[r--];
			else
				p2 += a[r--];
		}
		turn = 1 - turn;
	}

	cout << p1 << ' ' << p2;

}

int main(){
	faster();
	solve();
	return 0;
}

/*
 	(o_o)
____        __    
 /  / '_   / _)_  
(  /)/(-/)/(_)(//)
 _/_/ _/_ _  
(/ /__// (//) 
*/