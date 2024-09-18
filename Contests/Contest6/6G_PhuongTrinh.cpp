#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
#define pb push_back
#define MIN  1e-9

//Kiem tra xem nghiem da ton tai hay chua
bool checkFind(double x, double y){
	if(abs(x - y) < MIN) 
		return true;
	return false;
}

int main(){
	vector<double> res;
	bool checkVsNghiem = false;
	
	int n; cin >> n;
	while(n--){
		int a, b, c; cin >> a >> b >> c;
		if(a == 0 && b == 0) {
			if(c == 0) checkVsNghiem = true;
			else continue;
		}
		else if (a == 0){
			double x = -1.0 * c / b;
			//Kiem tra xem nghiem da ton tai hay chua
			bool found = false;
			for(auto nghiem : res){
				if(checkFind(x, nghiem)){
					found = true;
				}
			}
			if(!found) res.pb(x);
		}
		else{
			int delta = b * b - 4 * a * c;
			if(delta == 0){
				double x = -1.0 *b / (2.0 * a);
				//Kiem tra xem nghiem da ton tai hay chua
				bool found = false;
				for(auto nghiem : res){
					if(checkFind(x, nghiem)){
						found = true;
					}
				}
				if(!found) res.pb(x);
			}
			else if(delta > 0){
				double x1 = (-b + 1.0 * sqrt(1.0 * delta)) / (2.0 * a);
				double x2 = (-b - 1.0 * sqrt(1.0 * delta)) / (2.0 * a);
				//Kiem tra xem nghiem da ton tai hay chua
				bool found1 = false, found2 = false;
				for(auto nghiem : res){
					if(checkFind(x1, nghiem)){
						found1 = true;
					}
					if(checkFind(x2, nghiem)){
						found2 = true;
					}
				}
				if(!found1) res.pb(x1);
				if(!found2) res.pb(x2);
			}
		}
	}
	if(checkVsNghiem) cout << -1;
	else cout << res.size();
	return 0;
}
