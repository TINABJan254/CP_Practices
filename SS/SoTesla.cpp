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

ll mulMod(ll a, ll b) {
    if (b == 0) return 0;
    if (b == 1) return a;

    ll tmp = mulMod(a, b/2);
    if (b & 1) return ((tmp + tmp) % MOD + a) % MOD;
    return (tmp + tmp) % MOD;
}

struct Matrix {
    ll a[3][3];

    Matrix operator * (Matrix &other){
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
};

Matrix powMod(Matrix A, ll p) {

    if (p == 0) {
        Matrix I;
        I.a[0][0] = 1;
        I.a[0][1] = 0;
        I.a[0][2] = 0;
        I.a[1][0] = 0;
        I.a[1][1] = 1;
        I.a[1][2] = 0;
        I.a[2][0] = 0;
        I.a[2][1] = 0;
        I.a[2][2] = 1;
        return I;
    }

    if (p == 1) return A;

    Matrix tmp = powMod(A, p/2);
    if (p & 1) return tmp * tmp * A;
    return tmp * tmp;

}

void solve(){
    ll n; cin >> n >> MOD;

    if (n == 1) {cout << "1\n"; return;}
    if (n == 2) {cout << "2\n"; return;}
    if (n == 3) {cout << "3\n"; return;}

    Matrix x;
    x.a[0][0] = 1;
    x.a[0][1] = 2;
    x.a[0][2] = 3;
    x.a[1][0] = 1;
    x.a[1][1] = 0;
    x.a[1][2] = 0;
    x.a[2][0] = 0;
    x.a[2][1] = 1;
    x.a[2][2] = 0;

    Matrix res = powMod(x, n-3);
    cout << ((3*res.a[0][0] + 2*res.a[0][1]) % MOD + res.a[0][2]) % MOD << endl;

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
 *    created: 13-08-2025 16:52:51
**/

/*
    Dãy số Tesla được xây dựng như sau.
    T(i) = i với i ≤ 3.
    T(i) = T(i-1) + 2 × T(i-2) + 3 × T(i-3) với i ≥ 4.
    Nhiệm vụ của bạn là hãy tìm số Tesla thứ N theo modulo BASE cho trước.

    Input.
    Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
    Mỗi test gồm hai số nguyên dương N và BASE (N ≤ 10^9, BASE ≤ 10^12).

    Output.
    Với mỗi test, hãy in ra đáp án tìm được trên một dòng.

    Test ví dụ.
    Input
    6
    1 1000
    2 1000
    3 1000
    4 1000
    5 1000
    1000 1000000007

    Output
    1
    2
    3
    10
    22
    87329989

    Ý tưởng:
    Bài này sẽ giải tương tự bài fibonaci, tuy nhiên sử dụng ma trận A khác và ma trận nhân với A cũng khác
    Cách xây dựng ma trận A, mục đích của ma trận đó sẽ giúp ta tính đc Tn, và giữ lại các Tn-1, Tn-2 để tính tiếp sau này
    Ta có Tn = Tn-1 + 2*Tn-2 + 3*Tn-3
    Vì là truy hồi của 3 số trước đó => cần xây ma trận A 3x3, còn ma trận kết quả (chứa Tn) sẽ là ma trận 1x3
    Ma trận A:
        Hàng 1 của ma trận kết quả sẽ là Tn => hàng 1 ma trận basse phải chứa lần lượt là 1 2 3
        Hàng 2 của ma trật res sẽ cần lưu Tn-1 để tính cho lần sau => hàng 2 ma trận A là 1 0 0 (chỉ lấy Tn-1, số 0 nhân cho Tn-2,Tn-3 sẽ hết)
        Hàng 3 của ma trận res sẽ cần lưu Tn-2 để tính cho lần sau => hàng 3 ma trận A là 0 1 0 (chỉ lấy Tn-2)
        Vì số tesla Tn = Tn-1 + Tn-2 + Tn-3 => cần lấy 3 số gần nhất thôi

        vậy ma trận A sẽ là:
            1 2 3
            1 0 0
            0 1 0
        Ma trận nhân với ma trận A là 
            Tn-1
            Tn-2
            Tn-3
        
        Ta có công thức:
            Tn      1 2 3     Tn-1
            Tn-1 =  1 0 0  x  Tn-2
            Tn-2    0 1 0     Tn-3
        Mà ở đây, Ti = i (nếu i <= 3) => ta sẽ lấy mốc là T1, T2, T3
        Với bài toán tesla, số mũ của ma trận A là: n-3 (khác với bên fibo là n-1, có thể viết vài TH cụ thể để kiểm tra)
        
        Tổng quát lên và cuối cũng sẽ được: T[n] = X[1][1]*T3 + X[1][2]*T2 + X[1][3]*T1 = 3*X[1][1] + 2*X[1][2] + X[1][3]
        (Dùng phép nhân ma trận để chứng minh)

*/