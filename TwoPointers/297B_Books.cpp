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
    int n, t; cin >> n >> t;
    int a[n]; 
    for (int &x : a) cin >> x;

    int l = 0, r = 0;
    int ans = -1, curSum = 0;
    for (int r = 0; r < n; r++){
        curSum += a[r];
        while (curSum > t){
            curSum -= a[l];
            ++l;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans;
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        //freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    solve();
    return 0;
}
/*

*/