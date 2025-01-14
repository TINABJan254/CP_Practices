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
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vi tmp(b, b + m);
    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0;
    map<int, int> mp;
    while (j < m){
        while (i < n && a[i] <= b[j]){
            ++i;
        }
        mp[b[j++]] = i;
    }

    for (int x : tmp) cout << mp[x] << ' ';
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        freopen("outputf.txt", "w", stdout);
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