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

ll ledendre(ll p, ll n) {
    ll ans = 0;
    for (ll i = p; i <= n; i *= p) {
        ans += n/i;
    }
    return ans;
}

void solve(){
    ll n, k; cin >> n >> k;

    ll ans = LLONG_MAX;
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0) {
            ll cnt = 0;
            while (k % i == 0) {
                ++cnt;
                k /= i;
            }       
            ans = min(ans, ledendre(i, n)/cnt);
        }
    }   

    if (k > 1) {
        ans = min(ans, ledendre(k, n));
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
    cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
    Tìm số nguyên M lớn nhất sao cho N! chia hết cho K^M.
    Input:
    Dòng đầu tiên là số lượng bộ test T (T <= 100).
    Mỗi test gồm 2 số nguyên dương N và K (N <= 10^18, K <= 10^12).
    Output: 
    In ra số nguyên M tìm được.

    Ý tưởng: 
        Bài này sẽ dễ hơn nếu K là 1 snt, khi đó chỉ cần áp dụng cthuc legendre
        Ta phân tích N! và K^M thành thừa số nguyên tố
            N!  = p1^a1 * ... * pk^ak * Y
            K^M = (p1^b1 * ... * pk^bk) ^ M 
                = p1^(b1*M) * p2^(b2*M) * ... * pk^(bk * M)

            Để N! chia hết cho K^M thì (bậc các tsnt trong N! phải >= bậc các tsnt tương ứng trong K^M):
                a1 >= b1*M, a2 >= b2*M, ..., ak >= bk*M
             => M <= a1/b1 và M <= a2/b2 và ...và M <= ak/bk
             => M <= (bậc của pk trong N! / bk)
             => M = Min(a1/b1, ..., ak/bk)

    Cách làm:
        Không cần ptich N! thành tích các tsnt nữa mà chỉ cần ptich K sau đó với
        mỗi tsnt pj của K ta đi tìm bậc của nó trong N! bằng công thức legendre

        Ptich K thành tích các tsnt
        Với mỗi tsnt pj tìm bậc (số mũ) của pj trong N!
*/