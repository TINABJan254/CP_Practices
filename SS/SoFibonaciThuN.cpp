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

struct Matrix {
    ll a[2][2];
    Matrix operator * (Matrix &other){
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.a[i][j] += this->a[i][k] * other.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

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

    if (p & 1) return x * x * A;
    return x * x;

}

void solve(){
    ll n; cin >> n;
    Matrix x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;
    
    Matrix res = powMod(x, n - 1);
    cout << res.a[0][0] << endl;
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
 *    created: 12-08-2025 13:16:00
**/

/*
    Dãy số Fibonacci được xác định bằng công thức như sau.
    F[0] = 0, F[1] = 1.
    F[n] = F[n-1] + F[n-2] với mọi n >= 2.
    Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ....
    Nhiệm vụ của bạn là hãy xác định số Fibonacci thứ n.
    Do đáp số có thể rất lớn, in ra kết quả theo modulo 10^9+7.

    Input:
    Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).
    Mỗi test bàn gồm một số nguyên N (1 ≤ N ≤ 10^9).

    Output:
    Với mỗi test, in ra đáp án trên một dòng.

    Ví dụ:
    Input:
    3
    2
    6
    20
    Output:
    1
    8
    6765

    Kiến thức:
    Lũy thừa nhị phân:
        a^p =   a^(p/2) * a^(p/2) * a;  // nếu p lẻ 
                a^(p/2) * a^(p/2)       // nếu p chẵn
                a   // nếu p == 1
    Tính a*b (dùng chia để trị) 
        a*b =   a // nếu b == 1
                0 // nếu b == 0
                a*(b/2) + a*(b/2) + a   // nếu b lẻ
                a*(b/2) + a*(b/2)       // nếu b chẵn
    
    Lý thuyết: Notion
    Ở bài này ta có F1 = 1, F0 = 0

    Ta gọi X = A^(n-1)
    ⇒ F[n] = X[1][1] * F[1] + X[1][2] * F[0]
    ⇒ F[n] = X[1][1]

    Trong bài khi phép nhân a[i][k] * a[k][j] số chưa quá lớn nên chưa bị tràn
    Trong TH số quá lớn, để xử lý tràn ta sử dụng chia và trị để mulMod 2 số 
    (xem bài fibo_ver2 để biết)

*/