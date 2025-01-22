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

char a[1005][1005];

bool cmp(int x, int y){
    if (x < y) return a[x][y] == '1';
    return a[x][y] == '0';
}

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    vi v;
    for (int i = 0; i < n; i++){
        v.pb(i);
    }

    sort(v.begin(), v.end(), cmp);

    for (int x : v){
        cout << x + 1 << ' ';
    }

    cout << EL;
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