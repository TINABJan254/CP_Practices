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
    for (int i = 0; i < n; i++) cin >> a[i];
    
    multiset<int> ms;
    for (int x : a) {
        auto it = ms.lower_bound(x);
        if (it != ms.begin()) {
            --it;
            ms.erase(it);
        } 
        ms.insert(x);
    }
    cout << ms.sz;
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
    Tham khao
    D: Tạo một mảng f để chứa các tập cùng màu. Duyệt i từ đầu tới cuối, 
    tìm vị trí j đầu tiên trong f sao cho f[j] < a[i], sau đó thế f[j] = a[i]. 
    Do f giảm dần nên ta có thể binary search được j. 
    Đáp án là số lượng vị trí trong f khác 0.
*/