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

bool bs(ll *a, int L, int R, ll x){
    while (L <= R){
        int mid = (L + R) / 2;
        if (a[mid] == x)
            return true;
        else if (a[mid] > x)
            R = mid - 1;
        else
            L = mid + 1;
    }
    return false;
}

void solve(){
    int n;
    ll m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;
    ll x[n + 5];
    x[0] = x0;
    for (int i = 1; i <= n; i++){
        x[i] = (x[i - 1] % m * a % m + c ) % m;
    }

    // for (int i = 1; i <= n; i++) cout << x[i] << ' ';

    ll res = 0;
    for (int i = 1; i <= n; i++){
        if (bs(x, 1, n, x[i]))
            ++res;
    }

    cout << res << EL;

}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/