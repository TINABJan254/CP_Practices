#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		int a[n+1][m+1];
		int Stren = 0; //dem so khoi khac 0 (dien tich mat tren)
		for(int i =1; i <=n; i++){
			for(int j =1; j <=m; j++){
				cin >> a[i][j];
				if(a[i][j] != 0) Stren++;
			}
		}
		ll Sday = 2 * Stren; //dien tich mat tren va mat day
		//dien tich Sxq theo hang
		ll Sxq1 = 0;
		for(int i =1; i <=n; i++){
			Sxq1 += a[i][1] + a[i][m];
			for(int j =2; j <=m; j++){
				Sxq1 += abs(a[i][j] - a[i][j-1]);
			}
		}
		//dien tich Sxq theo cot
		ll Sxq2 = 0;
		for(int j =1; j <=m; j++){
			Sxq2 += a[1][j] + a[n][j];
			for(int i =2; i <=n; i++){
				Sxq2 += abs(a[i][j] - a[i-1][j]);
			}
		}
		cout << Sday + Sxq1 + Sxq2 << "\n";
	}
	return 0;
}
//5
//1 1
//1
//
//1 2
//1 2
//
//1 1
//2
//
//3 3
//1 1 1
//1 1 1
//1 1 1
//
//3 3
//1 1 1
//1 2 0
//1 0 2
