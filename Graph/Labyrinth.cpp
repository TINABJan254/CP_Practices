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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
string dir = "ULRD";

int n, m;
pii st, en;
char a[1005][1005];
bool visited[1005][1005];
int d[1005][1005];

void BFS(){
    queue<pii> q;
    q.push(st);
    visited[st.fi][st.se] = true;
    while (!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int k = 0; k < 4; k++){
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (x1 <= n && x1 > 0 && y1 <= m && y1 > 0 && !visited[x1][y1] && a[x1][y1] != '#'){
                q.push({x1, y1});
                d[x1][y1] = k;
                visited[x1][y1] = true;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'A') st = {i, j};
            if (a[i][j] == 'B') en = {i, j};
        }
    }

    memset(d, 0, sizeof(d));
    memset(visited, false, sizeof(visited));
    BFS();
    if (!visited[en.fi][en.se])
        cout << "NO";
    else{
        cout << "YES\n";
        int u = en.fi;
        int v = en.se;
        string path = "";
        while (u != st.fi || v != st.se){
            int pos = d[u][v];
            path += dir[pos];
            u -= dx[pos];
            v -= dy[pos];
        }
        reverse(path.begin(), path.end());
        cout << path.sz << EL << path;
    }
}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/