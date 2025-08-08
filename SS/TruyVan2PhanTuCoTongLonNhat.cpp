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

struct Data{
    int index;
    int value;

    Data(int idx = 0, int v = 0): index(idx), value(v){}

};

int n, m;
Data tree[N * 4];
int a[N];

Data mergeNode(Data& l_node, Data& r_node) {
    return (l_node.value >= r_node.value) ? l_node : r_node;
}

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node].index = tl;
        tree[node].value = a[tl];
    } else {
        int mid = (tl + tr) / 2;
        build(2*node, tl, mid);
        build(2*node + 1, mid + 1, tr);

        tree[node] = mergeNode(tree[2*node], tree[2*node + 1]);
    }   
}

void update(int node, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        tree[node].value = val; 
    } else {
        int mid = (tl + tr) / 2;
        if (idx <= mid) {
            update(2*node, tl, mid, idx, val);    
        } else {
            update(2*node + 1, mid + 1, tr, idx, val);
        }

        tree[node] = mergeNode(tree[2*node], tree[2*node + 1]);
    }
}

Data getM(int node, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return Data(0, -1);
    if (l <= tl && tr <= r) return tree[node];  

    int mid = (tl + tr) / 2;
    Data node1 = getM(2*node, tl, mid, l, r);
    Data node2 = getM(2*node + 1, mid + 1, tr, l, r);

    return mergeNode(node1, node2);
}

int query(int l, int r) {
    Data max1 = getM(1, 1, n, l, r);
    int max2_value = max(getM(1, 1, n, l, max1.index-1).value, getM(1, 1, n, max1.index + 1, r).value);
    return max1.value + max2_value;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    // for (int i = 1; i <= 25; i++) cout << i << " " << tree[i].index << " " << tree[i].value << endl;    

    while (m--) {
        string x; cin >> x;
        if (x == "U") {
            int u, v; cin >> u >> v;
            update(1, 1, n, u, v);
        } else {
            int l, r; cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }

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
    // cin >> TC;


    while (TC--){
      solve();
    }
    return 0;
}
/**
 *    author:  thienban
 *    created: 08-08-2025 21:31:32
**/

/*
    Cho dãy số A = A[1], A[2], …, A[N] (0 <= A[i] <= 10^8). 
    Có 2 loại truy vấn như sau:
    +) U u val: Thay giá trị A[u] = val (val <= 10^8).

    +) Q u v: Yêu cầu tìm ra 2 phần tử i, j nằm trong đoạn [u, v] (i khác j) sao cho tổng A[i] + A[j] là lớn nhất có thể.

    Input:
    Dòng đầu tiên là số lượng phần tử N và số lượng truy vấn M (N, M <= 100 000).
    M dòng tiếp, mỗi dòng gồm 1 dạng truy vấn.
    Output: 
    Với mỗi truy vấn loại 1, hãy in ra đáp án tìm được trên một dòng.

    Test ví dụ:   
    Input
    5 4
    1 2 3 4 5
    Q 2 5
    Q 2 4
    U 1 8
    Q 1 5
    
    Output
    9
    7
    13

    Ý tưởng:
        Với tìm max, ta làm tương tự tìm min
        Mỗi node ta sẽ lưu cả index, value max của đoạn mà node đó quản lý
        Ta sẽ tiến hành tìm kiếm max 2 lần để được 2 giá trị lớn nhất
        Khi đã tìm được max1, ta tiến hành tìm max2 bằng cách vẫn tìm trong đoạn đó
        nhưng bỏ qua max1, tức là tìm trong đoạn (L->idx_max1 - 1), (idx_max1 + 1 -> R)
*/