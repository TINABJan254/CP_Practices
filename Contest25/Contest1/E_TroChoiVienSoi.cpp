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

ll fibo[92];

void init() {
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i < 92; i++) fibo[i] = fibo[i-1] + fibo[i-2];
}

void solve(){
    ll n; cin >> n;
    ll res = LLONG_MAX;
    for (int i = 91; i >= 0; i--){
        if (fibo[i] <= n) {
            res = min(res, fibo[i]);
            n -= fibo[i];
        }
    }
    cout << res << EL;
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
    init();
    int TC = 1; 
    // cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
    Đây là Fibonaci Nim (trò chơi trừ toán học)
    Quy tắc của trò chơi đc trình bày rõ ở đề bài
    Nhiệm vụ bây giờ là biểu diễn n sử dụng biểu diễn Zeckendorf
        Zeckendorf là cách biểu diễn n thành tổng các số Fibonaci không liên tiếp (tức ko có 2 số fibonaci liên tiếp)
        Cách biểu diễn:
            Chọn số Fibonacci lớn nhất ≤ n.
            Trừ số đó khỏi n.
            Lặp lại bước 1 với phần còn lại, không chọn số Fibonacci liền kề với số vừa chọn.
            Kết thúc khi phần còn lại là 0.

    Đáp án sẽ là số fibonaci nhỏ nhất trong biểu diễn Zeckendorf
*/