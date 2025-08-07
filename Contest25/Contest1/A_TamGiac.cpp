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

//check 3 diem thang hang
bool check(pii p1, pii p2, pii p3){
    int x1 = p1.fi, y1 = p1.se;
    int x2 = p2.fi, y2 = p2.se;
    int x3 = p3.fi, y3 = p3.se;

    int VT = (y3 - y1) * (x2 - x1);
    int VP = (y2 - y1) * (x3 - x1);

    return (VT == VP);
}

void solve(){
    int n; 
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y;
        v.pb({x, y});
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!check(v[i], v[j], v[k])) ++cnt;
            }
        }
    }

    cout << cnt << EL;
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    // iof();
    faster();
    int TC = 1;
    while (TC--){
        solve();
    }
    return 0;
}
/*
	A: Duyệt trâu 3 điểm trong tập, kiểm tra xem chúng có thẳng hàng hay không. 
    Nếu có thì không thể tạo được tam giác từ 3 điểm này. 
    Có thể dùng cross product để kiểm tra để tránh việc sử dụng số thực.
B: Gọi dp[i] là số cách để tạo được xâu s[1:i]. 
Khi đó dp[i] bằng tổng của các dp[j] sao cho s[j+1:i] tồn tại trong từ điển. 
Để chuyển trạng thái nhanh ta có thể dựng Trie và xây suffix link bằng Aho-corasick từ tập từ trong từ điển.

C: Tìm vị trí L đầu tiên là “A” và vị trí R cuối cùng là “Z”, đáp án sẽ là R – L + 1.

D: Tạo một mảng f để chứa các tập cùng màu. Duyệt i từ đầu tới cuối, 
tìm vị trí j đầu tiên trong f sao cho f[j] < a[i], sau đó thế f[j] = a[i]. 
Do f giảm dần nên ta có thể binary search được j. 
Đáp án là số lượng vị trí trong f khác 0.

E: https://en.wikipedia.org/wiki/Fibonacci_nim. 
Phân tích n bằng tổng các số fibonacci phân biệt. 
Đáp án sẽ là số fibonacci nhỏ nhất.

F: Xử lí số nguyên lớn, có thể dùng python hoặc java cho nhanh.
G: Binary search số lượng thao tác nhiều nhất có thể thực hiện. 
Giả sử số thao tác là M. 
Để kiểm tra xem M có thể biến A thành dãy không giảm hay không, với mỗi a[i] tính khoảng mà nó có thể biến đổi đến được (a[i] -> (a[i] + M) mod m), sau đó dùng tham lam để tính giá trị nhỏ nhất mà a[i] có thể biến đổi được (a[i] phải >= a[i – 1]).
H: Giả sử A < B. Tìm k nhỏ nhất để A + k * (k + 1) / 2 = C >= B. Đặt d = C – B. Nếu d chẵn thì kết quả là k, do ta có thể chuyển thao tác cộng d / 2 từ A sang B. Nếu d lẻ: nếu k + 1 lẻ thì đáp án sẽ là k + 1, do sau khi tăng k + 1 vào A thì d sẽ chẵn; còn nếu k + 1 chẵn thì đáp án sẽ là k + 2 do sau khi tăng k + 1 và k + 2  vào A thì d sẽ chẵn.
I: Phân tích C(K, N) thành tích các thừa số nguyên tố sau đó dùng công thức tính số ước để tính. Do không thể tính trực tiếp C(K, N) vì kết quả ra rất lớn nên cần dùng công thức n! / k!(n-k)! để thay thế.
J: Chi phí đi từ i tới j có thể viết lại bằng p[i] + max(0, h[j] – (h[i] + p[i])). Sort lại mảng ban đầu theo h. Ta có thể tham lam như sau: Duyệt i từ 2 tới n, duy trì mx là giá trị lớn nhất của h[j] + p[j] mà j < i. Khi đó đáp án được cộng thêm một lượng = max(0, h[i] – mx).
*/
