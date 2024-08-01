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

int n;
int a[550][550];
int d;

void DFS(int i, int j, int x){
    if (d > x)
        return;
    a[i][j] = x;
    
     if (i + 1 < n && a[i + 1][j] == 0){
        ++d;
        DFS(i + 1, j, x);
    }

    if (j - 1 >= 0 && a[i][j - 1] == 0){
        ++d;
        DFS(i, j - 1, x);
    }
   
}

void solve(){
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++){
        d = 1;
        int x; cin >> x;
        DFS(i, i, x);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++)
            cout << a[i][j] << ' ';
        cout << EL;
    }

}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/