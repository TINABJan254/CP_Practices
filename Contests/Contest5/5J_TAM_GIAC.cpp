#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main(){
	int n; cin >> n;
	int a[n+1];
	for(int i =1; i <=n; i++) cin >> a[i];

	int l = 1; int res = 0;
	multiset<int> se;
	for(int r =1; r <=n; r++){
		se.insert(a[r]);
		if(se.size() >= 3){
			auto it = se.begin();
			it++;
			//cout << *se.begin() << " " << *it << " " << *se.rbegin();
			if(*se.begin() + *it > *se.rbegin()){
				res = max(res, r - l + 1);
			}
			else{
				se.erase(se.find(a[l]));
				l++;
			}
		}
	}
	cout << res << endl;
	return 0;
}

