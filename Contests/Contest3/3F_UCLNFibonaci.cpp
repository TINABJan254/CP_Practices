#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

ll MOD;
const int N = 1e6 + 5;

struct Matrix{
    ll A[2][2];
    Matrix operator * (Matrix &other){
        Matrix res;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                res.A[i][j] = 0;
                for (int k = 0; k < 2; k++){
                    res.A[i][j] += this->A[i][k] * other.A[k][j];
                    res.A[i][j] %= MOD;
                }
            } 
        }
        return res;
    }
};

Matrix binPow(Matrix a, ll n){
    if (n == 1){
        return a;   
    }
    Matrix x = binPow(a, n / 2);
    if (n % 2 == 0){
        return x * x;
    }
    else{
        return x * x * a;
    }
}

ll gcd(ll a, ll b){
    while (b != 0){
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve(){
    ll a, b;
    cin >> a >> b >> MOD;
    Matrix x1;
    x1.A[0][0] = 1;
    x1.A[0][1] = 1;
    x1.A[1][0] = 1;
    x1.A[1][1] = 0;
    
    ll uc = gcd(a, b);

    x1 = binPow(x1, uc);

    ll res = x1.A[0][1];
    cout << res << EL;
}

int main(){
    faster();
    int TC; cin >> TC;
    while (TC--){
        solve();
    }
    return 0;
}