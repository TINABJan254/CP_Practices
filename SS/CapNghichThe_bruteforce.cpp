#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll f = 0;
        for (int j = 0; j < a[i]; j++) f += mp[j];
        ans += f;
        mp[a[i]]++;
    }

    cout << ans << endl;
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC = 1; 
    // cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
    Cặp nghịch thế (code trâu)
    Ý tưởng: ta đếm phía sau a[i] có bao nhiêu số ptử bé hơn a[i]
    Cách làm:
        Đi từ cuối về để đếm số lần xuất hiện của các ptử
        Với mỗi ptử a[i] đc xét, ta cộng số lần xuất hiện các số từ 1 -> a[i]-1 vào kết quả
        Vì sao lại cộng được là bởi vì ta đã đi từ cuối về => các số này chắc chắn đã xuất hiện
        phía sau a[i]
*/