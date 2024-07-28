#include<bits/stdc++.h>
using namespace std;
#define ll long long
int maxn = 200000;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //init
    string s; cin >> s;
    int sz = s.size();
    s = " " + s;
    
    int n; cin >> n;
    int a[maxn+5]; memset(a, 0, sizeof(a));
    for(int i =1; i <=n; i++){
    	int x; cin >> x;
    	a[x] += 1;
    	a[sz - x + 2] -= 1;
	}
	ll res = 0;
	for(int i =1; i <=sz/2; i++){
		res += a[i];
		if(res % 2 == 1){
			swap(s[i], s[sz - i + 1]);
		}
	}
	for(int i =1; i <=sz; i++) cout << s[i];
    return 0;
}
