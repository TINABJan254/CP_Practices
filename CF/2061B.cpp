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

map<int, int> mp;

bool cmp(int x, int y){
    if (mp[x] != mp[y]) return mp[x] > mp[y];
    return x < y;
}

void solve(){
    int n; cin >> n;
    int a[n]; 
    
    mp.clear();
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a, a + n, cmp);
    if (a[0] == a[1] && a[2] == a[3]){
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << EL;
    } else if (a[0] == a[1]){
        int d = a[0] + a[1];
        for (int i = 2; i < n - 1; i++){
            d += a[i];
            if (d > a[i + 1]){
                cout << a[0] << ' ' << a[1] << ' ' << a[i] << ' ' << a[i + 1] << EL;
                return;
            }
            d -= a[i];
        }
        cout << "-1\n";
    } else {
        cout << "-1\n";
    }
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC; cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*

*/