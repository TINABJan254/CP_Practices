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
const int N = 1e7 + 5;

void ptich(int n, map<int, int> &mp) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            mp[i] += cnt;
        }
    }
    if (n > 1) mp[n]++;
}

void solve(){
    int m; cin >> m;

    map<int, int> mp;

    ptich(m, mp);
    ptich(m+1, mp);
    ptich(m+2, mp);

    // for (auto it: mp) {
    //     cout << it.fi << " " << it.se << endl;
    // }

    int t1 = 1, t2 = 1;
    for (auto it : mp) {
        t1 *= (it.se + 1);
        t2 *= (it.se*2 + 1);
    }
    --t1; --t2;

    // cout << t1 << " " << t2 << endl;

    cout << (t2 - t1*2) / 2 << endl;

    // cout << endl;
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        freopen("../build/outputf.txt", "w", stdout);
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
    Trong toán học, nếu số nguyên a chia hết cho số nguyên d thì số d được gọi là ước của số nguyên a, a được gọi là bội của d. 
    Trong bài toán này, với một số nguyên n, chúng ta sẽ quan tâm đến các ước của n2 thỏa mãn điều kiện: nhỏ hơn n và không phải là ước của n.
    Yêu cầu: Cho số nguyên dương m, xét số n = m × (m+1) × (m+2), hãy đếm số ước của n2 thỏa mãn điều kiện: nhỏ hơn n và không phải là ước của n.
    Dòng đầu chứa số nguyên T là số bộ dữ liệu;
    T dòng sau, mỗi dòng chứa một số nguyên dương m.
    Output:
    Gồm T dòng, mỗi dòng là số ước của n2 thỏa mãn: nhỏ hơn n và không phải là ước của n.

    Ý tưởng:
        gọi x (x < n) là ước của n (Tập D)
        => n^2/x là ước của n^2 (n^2/x > n do tính đối xứng + ước của n cũng là ước của n^2)
        gọi y là ước của n^2 nhưng < n (Tập C)
        => n^2/y là ước của n^2 (n^2/y > n do tính đối xứng)
        
        gọi E là tập ước của n^2
        => size(E) = size(D)*2 + size(C)*2;
        (nhân 2 bởi vì tập đấy chỉ mới chứa các ước < n, chưa tính các ước đối xứng là n^2/x, n^2/y)

        => size(C) = (size(E) - size(D)*2)/2;

        Để tính số lượng ước ta ptich thành tsnt và sử dụng công thức
            n = p1^e1 *...* pk^ek
            => số ước T = (e1+1)*(e2+1)*...*(ek+1)
                lưu ý số lượng này tính cả ước là chính nó, nếu ko tính chính nó thì phải trừ đi 1
        
        Không nên tính n = m*(m+1)*(m+2) ra sau đó mới đi ptich tsnt, mà ta nên
        đi ptich tsnt từng thành phần riêng lẻ m, m+1, m+2. Vì chúng là tich của nhau nên
        bậc các tsnt có thể cộng vào nhau
        Với n^2 thì cũng không cần ptich lại mà chỉ cần lấy bậc các tsnt của n nhân 2 là đc
        (
            giải thích: 
            n = p1^e1 + p2^e2 + ... + pk^ek
            n^2 = (p1^e1 + p2^e2 + ... + pk^ek)^2
                = p1^(e1*2) + p2^(e2*2) + ... + pk^(ek*2)
        )
*/