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

ll MOD;
const int N = 1e6 + 5;

struct Matrix {
    ll a[2][2];
};

ll mulMod(ll a, ll b) {
    if (b == 0) return 0;

    ll x = mulMod(a, b/2);
    if (b & 1) return ((x + x) % MOD + a) % MOD;
    return (x + x) % MOD;
}

Matrix mulMatrix(Matrix A, Matrix B) {
    Matrix res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.a[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res.a[i][j] += mulMod(A.a[i][k], B.a[k][j]);
                res.a[i][j] %= MOD; //note MOD
            }
        }
    }
    return res;
}

Matrix powMod(Matrix A, ll p) {
    if (p == 0) {
        Matrix I;
        I.a[0][0] = 1; I.a[0][1] = 0;
        I.a[1][0] = 0; I.a[1][1] = 1;
        return I;
        // Matrix^0 = Ma tran don vi I
    }
    if (p == 1) return A;

    Matrix x = powMod(A, p/2);
    if (p & 1) return mulMatrix(mulMatrix(x, x), A);
    return mulMatrix(x, x);
}

void solve(){
    ll n; cin >> n >> MOD;
    Matrix x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;

    Matrix res = powMod(x, n-1);
    cout << (res.a[0][0] + res.a[0][1]) % MOD << endl; // note MOD
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
    cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}

/**
 *    author:  thienban
 *    created: 12-08-2025 14:46:40
**/

/*
    Công thức số Fibonacci.
    F[0] = 1, F[1] = 1.
    F[n] = F[n-1] + F[n-2] với n >= 2.
    Nhiệm vụ của bạn là hãy tìm số Fibonacci thứ n theo modulo BASE cho trước.

    Input.
    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
    Mỗi test gồm 2 số nguyên dương N và BASE.

    Output.
    Với mỗi test, hãy in ra đáp án tìm được trên một dòng.

    Giới hạn.
    Subtask 1 (33%): N ≤ 10^6, BASE ≤ 10^9.
    Subtask 2 (33%): N ≤ 10^15, BASE ≤ 10^9.
    Subtask 3 (33%): N ≤ 10^15, BASE ≤ 10^12.

    Lý thuyết: notion
    Ở đây ta thấy: F1 = 1, F0 = 1

        Ta gọi X = A^(n-1)
        ⇒ F[n] = X[1][1] * F[1] + X[1][2] * F[0]
        ⇒ F[n] = X[1][1] + X[1][2] (nhớ chia dư ở đây)
    
    Và ở đây với subtask3, BASE = 10^12 mà BASE là số dùng để chia dư làm cho kết quả
    luôn < BASE, vậy nên khi BASE = 10^12, hai số a,b có thể lên tới 10^12, chúng nhân với sau sẽ
    là 10^24 => tràn
    => ta cần sử dụng chia và trị để nhân + chia dư
    
*/