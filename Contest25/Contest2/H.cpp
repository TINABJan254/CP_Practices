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

int n, m;
int parent[200005], Sz[200005];

void make_set(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        Sz[i] = 1;
    }
}

int find_set(int u){
    if (u == parent[u])
        return u;
    return parent[u] = find_set(parent[u]);
}

bool union_sets(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if (x != y){ 
        if (Sz[x] < Sz[y]) swap(x, y);
        parent[y] = x; //Chon dai dien cua tap co nhieu phan tu hon lam dai dien cho tap con lai
        Sz[x] += Sz[y];
        return true;
    }
    return false;
}

void solve(){
    make_set();

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        union_sets(a, b);
    }

    int rooms = 0;
    for (int i = 1; i <= n; i++) {
        rooms = max(rooms, Sz[i]);
    }

    cout << rooms; 

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
    while (TC--){
      solve();
    }
    return 0;
}
/*
    
*/