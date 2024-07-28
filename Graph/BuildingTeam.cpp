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

int n, m;
vi adj[100005];
int d[100005];

void DFS(int u){
    for (int v : adj[u]){
        if (!d[v]){
            d[v] = 3 - d[u];
            DFS(v);
        }
        else{
            if (d[v] == d[u]){
                cout << "IMPOSSIBLE";
                exit(0);
            }
            
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++){
        if (!d[i]){
            d[i] = 1;
            DFS(i);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
}

int main(){
    faster();
    solve();
    return 0;
}

/*
Check do thi hai phia
https://cses.fi/problemset/task/1668/
*/