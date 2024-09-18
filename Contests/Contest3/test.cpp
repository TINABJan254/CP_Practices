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
    priority_queue<ll> q1; //q le
    priority_queue<ll, vector<ll>, greater<ll>> q2; //q chan
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x % 2 == 0)
            q2.push(x);
        else
            q1.push(x);
    }

    if (q1.empty() || q2.empty()){
        cout << "0\n";
        return;
    }

    ll res = 0;
    while (!q2.empty()){
        ll le = q1.top();
        ll chan = q2.top();
        if (chan > le){
            ++res;
            q1.pop();
            q1.push(chan + le);
        }
        else{
            ++res;
            q2.pop();
            q1.push(chan + le);
        }
    }

    cout << res << EL;
}

int main(){
    faster();
    int TC; cin >> TC;
    while (TC--){
        solve();
    }
    return 0;
}

/*

*/