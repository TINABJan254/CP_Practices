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

struct BIT {
    int n;
    vll tree;

    BIT(int size) : n(size), tree(size + 1, 0) {};

    void update(int i, ll v) {
        for (; i <= n; i += (i & -i)) tree[i] += v;    
    }

    ll get(int i) {
        ll ans = 0;
        for (; i; i -= (i & -i)) ans += tree[i];
        return ans;
    }

};

void solve(){
    BIT bit1(N), bit2(N);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll f[n] = {0}; // f[i] số lượng cặp nghịch thế tạo từ i
    for (int i = n - 1; i >= 0; i--) {
        f[i] = bit1.get(a[i] - 1);
        bit1.update(a[i], 1);
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += bit2.get(a[i] - 1);
        bit2.update(a[i], f[i]);
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
    Cho dãy số A[] có N phần tử. Hãy đếm số bộ ba các số thứ tự ngược, tức là A[i] > A[j] > A[k] với i < j < k.
    Input
    Dòng đầu tiên là số lượng bộ test (<= 20).
    Mỗi test gồm một số nguyên dương N (N <= 10^5)
    Dòng tiếp theo gồm N số nguyên dương A[i] (1 <= A[i] <= N).
    Output
    Với mỗi test, in ra đáp án tìm được trên một dòng.

    Ý tưởng:
    Ta sẽ đi tính số cặp j < k và a[j] > a[k] trước (sử dụng BIT)
    Sau đó đi tính số cặp i < j và a[i] > a[j], với mỗi i bắt cặp với 1 j, thì số lượng cặp
    (j, k) đó sẽ kết hợp được với i để tạo thành 1 bộ 3 nghịch thế (i, j, k)
    vd: 
        ta có 3 cặp (j1, k) rồi: 5-3, 5-2, 5-1, 5-0
        ta chọn đc cặp (i1, j1) là: 9-5 => số bộ ba += số lượng cặp (j1, k), số bộ 3 sẽ là: 4
        tương tự, nếu tìm đc (i2, j1) thỏa mãn, thì số bộ ba cũng sẽ += số lượng cặp (j1, k)

    Với tìm cặp (j, k) thì đã làm ở bài cặp nghịch thế
    Còn tìm căp (i, j) thì ta cũng làm tương tự, nhưng thay vì nếu gặp ptử đó ta tăng lên 1,
    thì ta đi cộng nó với số bộ cặp nghịch thế mà nó tạo ra được


*/