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
    int a[n];
    for (int &x : a) cin >> x;
    int l = a[0], r = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] + 1 == l){
            l = a[i];
        } else if (a[i] - 1 == r){
            r = a[i];
        } else {
            cout << "NO\n";
            return;
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
    iof();
    faster();
    int TC; cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
Chắc chắn các chỗ ngồi phải liên tiếp nhau => dùng left lưu số ghế nhỏ nhất, right lưu số ghế lớn nhất
https://codeforces.com/problemset/problem/2000/B
*/