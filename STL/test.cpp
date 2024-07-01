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
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int maxE = *max_element(a, a + n);
	if (n > 1 && maxE == a[n - 1]){
		int maxE1 = *max_element(a, a + n - 1);
		int res = maxE1 + maxE;
		for (int i = 0; i < n - 1; i++){
			if (a[i] == maxE1){
				if (a[i] == a[i + 1])
					++res;
			}
		}
		cout << res << EL;	
	}
	else{
		int res = maxE;
		for (int i = 0; i < n - 1; i++){
			if (a[i] == maxE){
				if (a[i] == a[i + 1])
					++res;
			}
		}
		cout << res << EL;	
	}
	
}

int main(){
	faster();
    int TC; cin >> TC;
    while (TC--){
    	solve();
    }
}

/*

*/	