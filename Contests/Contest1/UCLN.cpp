#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n+1];
	int maxn = 0;
    for(int i =1; i <=n; i++){
    	cin >> a[i];
    	maxn = max(maxn, a[i]);
	}
	
	int uoc[maxn+1]; memset(uoc, 0, sizeof(uoc));
	for(int i =1; i <=n; i++){
		uoc[a[i]]++;
	}
	
	bool check = false;
	for(int i =maxn; i >=1; i--){ //xet tung so 1 xem so nao la uoc cua 2 ptu trong mang
		int cntuoc = 0;
		for(int j =i; j <=maxn; j +=i){
			cntuoc += uoc[j];
			if(cntuoc >= 2){
				cout << i << endl;
				check = true;
				break;
			}
		}
		if(check) break;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

