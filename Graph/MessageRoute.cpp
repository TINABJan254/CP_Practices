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
bool visited[100005];
int parent[100005];

void BFS(int u){
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int x : adj[v]){
            if (!visited[x]){
                q.push(x);
                visited[x] = true;
                parent[x] = v;
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
    parent[1] = 1;
    BFS(1);
    if (!visited[n]){
        cout << "IMPOSSIBLE";
    }
    else{
        vi path;
        int u = n;
        while (parent[u] != u){
            path.pb(u);
            u = parent[u];
        }
        path.pb(1);
        reverse(path.begin(), path.end());
        cout << path.sz << EL;
        for (auto x : path)
            cout << x << ' ';
    }
}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/