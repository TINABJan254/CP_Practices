#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int n, st, en, u, d;
int main(){
	cin >> n >> st >> en >> u >> d;
	queue<pair<int, ll>> q;
	q.push({st, 0});
	set<int> se;
	se.insert(st);
	while(!q.empty()){
		auto top = q.front(); q.pop(); //top.fi: tang hien tai top.se: so buoc
		if(top.fi == en){
			cout << top.se << endl;
			return 0;
		}
		top.se++;
		if(top.fi - d >= 1 && se.find(top.fi - d) == se.end()){
			se.insert(top.fi - d);
			q.push({top.fi - d, top.se});
		}
		if(top.fi + u <= n && se.find(top.fi + u) == se.end()){
			se.insert(top.fi + u);
			q.push({top.fi + u, top.se});
		}
	}
	cout << -1 << endl;
}
