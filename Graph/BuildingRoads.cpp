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
bool visited[100005];

void BFS(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int x : adj[v]){
            if (!visited[x]){
                q.push(x);
                visited[x] = true;
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

    memset(visited, false, sizeof(visited));
    vi v;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            v.pb(i);
            BFS(i);
        }
    }

    cout << v.sz - 1 << EL;
    for (int i = 0; i < v.sz - 1; i++)
        cout << v[i] << " " << v[i + 1] << EL;

}

int main(){
    faster();
    solve();
    return 0;
}

/*
https://cses.fi/problemset/task/1666/
*/