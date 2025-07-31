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
const int N = 1e7 + 1;

int isPrime[N];
vi prime;

void sieve(){
    for (int i = 0; i < N; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    
    for (int i = 2; i <= sqrt(N); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = 0;
        }
    }

    for (int i = 2; i <= N; i++) if (isPrime[i]) prime.pb(i);

}

void solve(ll n){
    for (int i = 0; i < prime.sz; i++) {
        if (n % prime[i] == 0) {
            int cnt = 0;
            while (n % prime[i] == 0) {
                ++cnt;
                n /= prime[i];
            }
            cout << prime[i] << " " << cnt << EL;
        }
    }
    if (n > 1) cout << n << " 1" << EL;
    cout << EL;
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
    sieve();
    int TC = 1; 
    cin >> TC;
    while (TC--){
        ll n; cin >> n;
        solve(n);
    }
    return 0;
}
/*
    Với n=1e14, thì việc sinh sẵn các số nguyên tố <= 10^7 sẽ giúp mỗi vòng lặp phân tích n
    chúng ta chỉ cần lặp khoảng 10^5 lần => cải thiện hơn nhiều so với duyệt với sqrt(n) khi mà n lớn
*/