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

    vi a(n); 
    for (int &x : a) cin >> x;

    for (int i = 0; i < n-1; i++){
        if (a[i] > a[i + 1]){
            cout << "NO\n"; return;
        } else {
            a[i+1] -= a[i];
        }
    }

    cout << "YES\n";
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        //freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    // iof();
    faster();
    int TC; cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
a[i] > a[i+1] => no way
*/