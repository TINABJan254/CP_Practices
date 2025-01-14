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
    string s; cin >> s;
    int l = 0;
    int cnt[4] = {0};
    int ans = INT_MAX;
    for (int r = 0; r < s.sz; r++){
        cnt[s[r] - '0']++;
        while (cnt[1] >= 1 && cnt[2] >= 1 && cnt[3] >= 1){
            ans = min(ans, r - l + 1);
            cnt[s[l] - '0']--;
            ++l;
        }
    }
    cout << (ans == INT_MAX ? 0 : ans) << EL;
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
    int TC; cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
https://codeforces.com/problemset/problem/1354/B
*/