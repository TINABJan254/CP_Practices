
#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int, int> mp;
	int k; cin >> k;
	vector<int> v(k);
	for(int i =0; i <k; i++) cin >> v[i];
	int dem = 0;
	while(dem < k){
		for(int i =0; i <v[dem]; i++){
			int x; cin >> x;
			if(mp[x] == dem){
				mp[x]++;
			}
		}
		dem++;
	}
	for(auto x : mp){
		if(x.second == k){
			cout << x.first;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
