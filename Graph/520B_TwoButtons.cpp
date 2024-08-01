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

set<ll> used;

void solve(){
    ll n, m; cin >> n >> m;
    queue<pair<ll, ll>> q;
    q.push({n, 0});
    used.insert(n);
	while (!q.empty()){
        ll x = q.front().fi;
        ll cnt = q.front().se;
        q.pop();
        if (x == m){
            cout << cnt;
            return;
        }
        if (x * 2 <= 20000 && used.find(x * 2) == used.end()){
        	used.insert(x * 2);
        	q.push({x * 2, cnt+1});
		}
        	
        if (used.find(x - 1) == used.end() && x - 1 > 0){
        	used.insert(x - 1);
            q.push({x - 1, cnt + 1});
        }
    }
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/
