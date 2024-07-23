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
    int n, k; cin >> n >> k;
    int a[n + 5];
    for (int i = 0; i < n; i++) cin >> a[i];
    int minE = *min_element(a, a + n);
    for (int m = minE; m >= 1; m--){
        bool flag = true;
        for (int i = 0; i < n; i++){
            int r = a[i] % m;
            if (r > k){
                flag = false;
                break;
            }
            if (!flag)
                break;
        }
        if (flag) {
            cout << m << EL;
            break;
        }
    }

}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/