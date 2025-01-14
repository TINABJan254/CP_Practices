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
    ll s = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }

    if (s % 3 != 0){
        cout << "0\n";
        return;
    }

    ll target = s/3, curSum = 0;
    ll cnt[n] = {0}; //cnt[i] = 1 <=> a[i]+..+a[n] == target
    for (int i = n - 1; i >= 0; i--){
        curSum += a[i];
        if (curSum == target){
            cnt[i] = 1;
        }
    }

    ll p[n] = {0};
    p[n - 1] = cnt[n-1];
    for (int i = n-2; i >= 0; i--){
        p[i] = cnt[i] + p[i + 1];
    }

    curSum = 0;
    ll ans = 0;
    for (int i = 0; i < n-2; i++){
        curSum += a[i];
        if (curSum == target){
            ans += p[i + 2];
        }
    }

    cout << ans;
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
    solve();
    return 0;
}
/*
Xem tutorial
Ý tưởng: sẽ chia làm 3 dãy: dãy thứ 1 (0->i) dãy thứ 3 (j->n) dãy thứ 2 (i+1->j-1)
        ta sẽ đi xây dựng trước dãy 1 và dãy 3
        nếu tồn tại tại dãy 1, dãy 3 thì chắc chắn sẽ có dãy 2
        việc bây giờ là đi tính số cặp (i, j) có thể có trong dãy thôi (tức tính số cặp dãy 1, dãy 3)

    target = s/3
    cnt[i] = 1: nếu tổng các tử từ i->n = target
    khi gặp 1 vị trí tạo được dãy 1, thì đáp án sẽ bằng tổng các vị trí j tính từ i + 2 => có mảng cộng dồn
        các vị trí thỏa mãn là dãy thứ 3
        (chọn từ i + 2 vì trừa lại khoảng i+1 cho dãy thứ 2)

https://codeforces.com/problemset/problem/466/C
*/