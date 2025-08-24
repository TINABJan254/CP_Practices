#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

ll c[65][65];

void init(){
    for (int n = 0; n < 65; n++) {
        c[n][0] = c[n][n] = 1;
        for (int k = 1; k < n; k++) {
            c[n][k] = c[n-1][k-1] + c[n-1][k];
        }
    }
}

void solve(){
    ll a, b, k; cin >> a >> b >> k;
    string ans = "";
    while (a != 0 && b != 0) {
        ll cnt = c[a+b-1][a-1]; //số lượng xâu có thể tạo với pattern có vị trí hiện tại là a
        if (k <= cnt) {
            ans += "a";
            --a;
        } else {
            ans += "b";
            --b;
            k -= cnt;
        }
    }

    //phần còn lại
    ans.append(a, 'a');
    ans.append(b, 'b');

    cout << ans << endl;
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC = 1; 
    // cin >> TC;
    init();
    while (TC--){
      solve();
    }
    return 0;
}

/**
 *    author:  thienban
 *    created: 23-08-2025 22:56:35
**/

/*
    
*/