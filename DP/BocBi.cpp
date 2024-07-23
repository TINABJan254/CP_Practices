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
    int a[n + 5], b[n + 5];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll f1[n + 5] = {0};
    ll f2[n + 5] = {0};
    for (int i = 1; i <= n; i++){
        f1[i] = max(f1[i - 1], f2[i - 1] + a[i - 1]);
        f2[i] = max(f2[i - 1], f1[i - 1] + b[i - 1]);
    }
    cout << max(f1[n], f2[n]);
}

int main(){
	faster();
    solve();
}

/*

*/	