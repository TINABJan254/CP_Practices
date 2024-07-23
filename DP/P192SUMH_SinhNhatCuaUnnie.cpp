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

int a[5005][5005];
ll f[5005][5005];

void solve(){
    int n, m; cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            f[i][j] = f[i-1][j];
            for (int k = 0; k <= m; k++)
                if (k != j)
                    f[i][j] = max(f[i][j], f[i - 1][k] + a[i-1][j-1]);
        }
    }
    cout << *max_element(f[n] + 1, f[n] + m + 1);
}

int main(){
	faster();
    solve();
}

/*

*/	