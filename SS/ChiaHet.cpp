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
#define vll vector<ll>
#define vvl vector<vector<ll>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
    int n, m; cin >> n >> m;
    vll a;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a.pb(x);
    }

    vvl b;
    for (int i = 1; i <= m; i++) {
        vll tmp;
        for (int j = 0; j < n; j++) {
            ll x; cin >> x;
            tmp.pb(x);
        }
        b.pb(tmp);
    }
    

    for (int i = 0; i < m; i++) {
        vll tmp_a = a;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ll gcd = __gcd(tmp_a[j], b[i][k]);
                tmp_a[j] /= gcd;
                b[i][k] /= gcd;
            }
        }
    }

    vi res;
    for (int i = 0; i < m; i++) {
        bool check = true;
        for (int j = 0; j < n; j++) 
            if (b[i][j] != 1) {
                check = false;
                break;
            }
        if (check) res.pb(i+1);
    }

    cout << res.sz << EL;
    for (auto x : res) cout << x << " ";
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
    // cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}
/*
    Cho dãy số {A[1], A[2], …, A[N]} và M dãy số {B[i][1], B[i][2], …, B[i][N]}.

Với mỗi truy vấn, bạn cần trả lời xem tích A[1]*A[2]*…*A[N] có chia hết cho tích B[i][1]*B[i][2]*…*B[i][N] hay không?

Input:

Dòng đầu tiên là hai số nguyên N và M (N, M <= 100).

Dòng tiếp theo gồm N số nguyên A[i].

M dòng tiếp, mỗi dòng là một truy vấn gồm N số nguyên B[i][1], B[i][2], ..., B[i][N].

Output: 

Dòng đầu tiên in ra số bộ dãy số B[] thỏa mãn. Dòng thứ 2 in ra lần lượt chỉ số bộ dãy thứ i thỏa mãn yêu cầu.

Giới hạn:

Subtask 1 (50%): Các số có giá trị không vượt quá 10000.

Subtask 2 (50%): Các số có giá trị không vượt quá 1015.

Ý tưởng:
    A* / B*
    Ta làm tương tự như rút gọn phân số, lần lượt rút gọn các ptử của B cho mỗi ptử của A
    nếu như rút gọn đến khi B* (tích các ptử mảng B) hết (=1) thì chia hết

Cách làm TLE: 
    Ptich A*, B* thành tsnt, để A* chia hết cho B* thì bậc các tsnt trong B* không được vượt 
    quá bậc của các tsnt tương ứng trong A*
*/