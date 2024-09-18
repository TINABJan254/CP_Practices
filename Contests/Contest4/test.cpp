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
    map<char, int> mp;
    for (int i = 0; i < n; i++){
        char x; cin >> x;
        mp[x]++;
    }

    int n_add = mp['+'], n_sub = mp['-'];
    int q; cin >> q;
    while (q--){
        int x, y;
    }

}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/