#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define COUNT_ONE(x) __builtin_popcountll((x))
#define COUNT_LEAD_ZERO(x) __builtin_clzll((x))
#define COUNT_TRAIL_ZERO(x) __builtin_ctzll((x))
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ll MOD;

ll mulMod(ll a, ll b){
    ll res = 0;
    a %= MOD;
    while(b){
        if(b & 1){
            res = (res + a) % MOD;
        }
        a = a * 2 % MOD;
        b /= 2;
    }
    return res;
}

struct Matrix{
    ll a[2][2];

    friend Matrix operator * (Matrix x, Matrix y){
        Matrix z;
        FOR(i, 0, 1){
            FOR(j, 0, 1){
                z.a[i][j] = 0;
                FOR(k, 0, 1){
                    z.a[i][j] = (z.a[i][j] % MOD) + mulMod(x.a[i][k], y.a[k][j]);
                    z.a[i][j] %= MOD;
                }
            }
        }
        return z;
    }
};

Matrix powMod(Matrix x, ll p){
    if(p == 0) {
        Matrix I;
        I.a[0][0] = 1; I.a[0][1] = 0;
        I.a[1][0] = 0; I.a[1][1] = 1;
        return I;
    }
    Matrix half = powMod(x, p / 2);

    Matrix res = half * half;
    if(p & 1){
        res = res * x;
    }
    return res;
}

void HuyenMay(){   
    ll p; cin >> p >> MOD;

    Matrix x;
    x.a[0][0] = 1; x.a[0][1] = 1;
    x.a[1][0] = 1; x.a[1][1] = 0;

    Matrix res = powMod(x, p + 1);
    cout << res.a[1][0] << endl;
}   

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    faster();
    iof();
    int t = 1;
    cin >> t;
    while(t--){
        HuyenMay();
    }
    return 0;
}

/*
    HungLam
*/