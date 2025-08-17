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

const ll MOD = 1e15 + 7;
const int N = 1e6 + 5;

ll mulMod(ll a, ll b) {
    if (b == 0) return 0;
    if (b == 1) return a;

    ll tmp = mulMod(a, b/2);
    if (b & 1) return ((tmp + tmp) % MOD + a) % MOD;
    return (tmp + tmp) % MOD;
}

struct Matrix {
    ll a[3][3] = {};

    Matrix operator * (const Matrix &other){
        Matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    res.a[i][j] += mulMod(this->a[i][k], other.a[k][j]);
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    Matrix operator + (const Matrix &other) { // dùng const để chấp nhận cả biến thường và tạm (giá trị trả về)
        Matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.a[i][j] = (this->a[i][j] + other.a[i][j]) % MOD;
            }
        }
        return res;
    }

};

Matrix I;

Matrix powMod(Matrix A,  ll p) {
    if (p == 0) return I;
    if (p == 1) return A;

    Matrix x = powMod(A, p/2);
    if (p & 1) return x * x * A;
    return x * x;
}

Matrix sumMatrix(Matrix A, ll k) {
    if (k == 0) return Matrix();
    if (k == 1) return A;

    Matrix x = powMod(A, k/2);
    Matrix term = (I + x) * sumMatrix(A, k/2);
    if (k & 1) return term + powMod(A, k);
    return term;
}

void solve(){
    ll n; cin >> n;  

    if (n < 4) {
        if (n == 1) cout << "1\n";
        if (n == 2) cout << "3\n";
        if (n == 3) cout << "6\n";
        return;
    }

    Matrix x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[0][2] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;
    x.a[1][2] = 0;
    x.a[2][0] = 0;
    x.a[2][1] = 1;
    x.a[2][2] = 0;

    Matrix res = sumMatrix(x, n-3); //Hàm tính B(k)

    cout << ((3*res.a[0][0] + 2*res.a[0][1]) % MOD + res.a[0][2]) % MOD + 6<< endl;
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

    I.a[0][0] = 1;
    I.a[0][1] = 0;
    I.a[0][2] = 0;
    I.a[1][0] = 0;
    I.a[1][1] = 1;
    I.a[1][2] = 0;
    I.a[2][0] = 0;
    I.a[2][1] = 0;
    I.a[2][2] = 1;

    int TC = 1; 
    cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}

/**
 *    author:  thienban
 *    created: 13-08-2025 20:38:50
**/

/*
    Dãy số Tribonacci được xây dựng như sau.
    T(i) = i với i ≤ 3.
    T(i) = T(i-1) + T(i-2) + T(i-3) với i ≥ 4.
    Nhiệm vụ của bạn là hãy tính tổng N phần tử đầu tiên của dãy số này.
    F(N) = T(1) + T(2) + … + T(N).

    Input.
    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
    Mỗi test gồm một số nguyên dương N (N ≤ 10^9).

    Output.
    Với mỗi test, in ra đáp án tìm được theo modulo 10^15+7.

    Giới hạn.
    50% test có N ≤ 10000.

    Test ví dụ.
    Input
    5
    1
    2
    3
    4
    5

    Output
    1
    3
    6
    12
    23

    Ý tưởng:
        Việc tính số Tribonaci thì cũng dùng ma trận tương tự như fibo
        Thông qua bài số Tesla ta đã biết để tính Ti thì phải thông qua pow ma trận, tức mỗi A^k sẽ cho ta một Tm nào dó
        => Tổng của các số tribo sẽ là tổng các ma trận
        Sau khi tính được tổng các ma trận, ta cần lấy ma trận đó * với ma trận Tn-3 Tn-2 Tn-1 (như tesla)
        và phải cộng thêm T1, T2, T3 để cho đủ F(n) vì Fn bắt đầu từ T1 + .. + Tn
        
        Để tính tổng các ma trận nhanh ta dùng chia để trị, ta có công thức:
            Gọi B(k) = A + A^2 + ... + A^k (A là ma trận)

            Nếu K cgẵn
                B(k) = A + ... + A^(k/2) + A^(k/2+1) + ... + A^k
                    = A + ... + A^(k/2) + A^(k/2) * (A + ... + A^(k/2)) //đặt A^(k/2) ra ngoài -> thấy có nhân tử chung -> đặt nhân tử chung
                    = (I + A^(k/2)) * (A + ... + A^(k/2)) //1 ở trong ma trận sẽ là ma trận đơn vị)
                    = (I + A^(k/2)) * B(k/2)
            Nếu K lẻ
                B(k) = A + ... + A^(k/2) + A^(k/2+1) + ... + A^(k-1) + A^k // K lẻ thì ko chia hết cho 2 được -> thừa ra A^k
                    = A + ... + A^(k/2) + A^(k/2) * (A + ... + A^(k/2)) + A^k // K lẻ nên A^k ko thể chia ra làm A^k/2 * A^k/2
                    = (I + A^(k/2)) * B(k/2) * A^k

            Hàm sumMatrix(A, K) là hàm tính B(k) = A + .. + A^k
            Vậy bên B(k/2) = sumMatrix(A, k/2)

*/