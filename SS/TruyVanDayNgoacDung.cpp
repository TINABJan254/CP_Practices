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

struct Node {
    int maxAns;
    int open; 
    int close;

    Node(int ans = 0, int o = 0, int c = 0) : maxAns(ans), open(o), close(c){}
};

Node tree[4 * N];
string s;
int m;

Node mergeNode(Node l_node, Node r_node){
    int t = min(l_node.open, r_node.close);
    return Node(
        l_node.maxAns + r_node.maxAns + 2*t,
        l_node.open + r_node.open - t,
        r_node.close + l_node.close - t
    );
}

void build(int node, int tl, int tr){
    if (tl == tr) {
        if (s[tl] == '(') tree[node].open++;
        else tree[node].close++;
        tree[node].maxAns = 0;
    } else {
        int mid = (tl + tr) / 2;
        build(2 * node, tl, mid);
        build(2 * node + 1, mid + 1, tr);

        tree[node] = mergeNode(tree[2*node], tree[2*node+1]);
    }
}

Node query(int node, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return Node();
    if (l <= tl && tr <= r) return tree[node];

    int mid = (tl + tr) / 2;
    Node l_node = query(2 * node, tl, mid, l, r);
    Node r_node = query(2 * node + 1, mid + 1, tr, l , r);

    return mergeNode(l_node, r_node);
}

void solve(){
    cin >> s;

    build(1, 0, s.sz-1);

    // for (int i = 0; i < 50; i++) cout << i << " " << tree[i].maxAns << " " << tree[i].open << " " << tree[i].close << endl;

    cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        cout << query(1, 0, s.sz - 1, --l, --r).maxAns << endl;
    }

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
    Node lưu 3 thông tin
        maxAns: độ dài chuỗi con dài nhất là dãy ngoặc đúng (trong đoạn mà node đó quản lý)
        open: số dấu '(' không nằm trong maxAns
        close: số dấu ')' không nằm trong maxAns

    Thao tác mergeNode là một công thức quy hoạch động 
        Ta có 2 node A(left), B(right) => X = merge(A, B)
        t = min(A.open, B.open) - dấu mở bên phải kết hợp với dấu đóng bên trái
        X.maxAns = A.maxAns + B.maxAns + t*2; (*2 bởi vì 1 cặp có độ dài 2)
        X.open = A.open + B.open - t;
        X.close = A.close + B.close - t;

        A = (()() 
            A.maxAns = 4
            A.open = 1
            A.close = 0

        B = ()))
            B.maxAns = 2
            B.open = 0
            B.close = 2

        X = A + B = (()()()))
            t = 1
            X.maxAns = 4 + 2 + 1*2 = 8
            X.open = 0
            x.close = 1

*/