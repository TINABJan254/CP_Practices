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
    int a[n], b[n];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int t1[n], t2[n];
    for (int i = 0; i < n; i++){
        t1[i] = a[i] - b[i];
        t2[i] = b[i] - a[i];
    }

    int maxPos = max_element(t2, t2 + n) - t2;
    bool check = true;
    for (int i = 0; i < n; i++){
        if (t1[i] < t2[maxPos] && i != maxPos){
            check = false;
            break;
        }
    }

    if (check){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

void local(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        //freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    local();
    faster();
    int TC; cin >> TC;
    while (TC--){
        solve();
    }
    return 0;
}
/*

*/