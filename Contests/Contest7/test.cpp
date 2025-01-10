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

int fre[1000005];

void solve(){
	int n; cin >> n;
	int a[n + 5];
	int maxE = -1;
	memset(fre, 0, sizeof(fre));
	for (int i = 0; i < n; i++){
		cin >> a[i];
		maxE = max(maxE, a[i]);
		fre[a[i]]++;
	}

	for (int uoc = maxE; uoc >= 1; uoc--){
		int cnt = 0;
		for (int boi = uoc; boi <= maxE; boi += uoc){ //boi là các bội của uoc
			cnt += fre[boi];
		}
		if (cnt >= 2){
			cout << uoc << EL;
			break;
		}
	}
}

int main(){
//	faster();
//	int TC; cin >> TC;
//	while (TC--){
//	    solve();
//	}
	
	int a = 0;
	if (a = 0){
		cout << "Zero";
	}
	else{
		cout << "Non-zero";
	}

	return 0;
}

/*
tìm ước từ số lớn nhất trong mảng
nếu tồn tại 2 số là bội của của ước đó thì ước đó thỏa mãn
*/
