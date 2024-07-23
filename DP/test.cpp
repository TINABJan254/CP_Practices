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

void solve(){
    int n, m; cin >> n >> m;
    int a[n + 5][m + 5];
    int b[n + 5][m + 5];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> a[i][j];    
            b[i][j] = a[i][j];
        }

    for (int i = 0; i < n; i++){
        b[i][m] = b[i][0];
        for (int j = 0; j < m; j++)
            b[i][j] = b[i][j + 1];
    }

    for (int i = 0; i < m; i++){
        b[n][i] = b[0][i];
        for (int j = 0; j < n; j++) 
            b[j][i] = b[j + 1][i];
    }

    int flag = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == b[i][j])
                flag = -1;

    if (flag == -1){
        cout << flag << EL;
    }
    else{
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                cout << b[i][j] << ' ';
            cout << EL;
        }
    }

}

int main(){
	faster();
    int TC; cin >> TC;
    while (TC--){
        solve();
    }
}

/*

*/	