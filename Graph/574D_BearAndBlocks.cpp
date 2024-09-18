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
	int n; cin >> n;
	int a[n + 5];
	int f[n + 5]; //lưu số bước cần thiết để phá hủy cột i

	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		f[i] = a[i];
	}

	f[0] = f[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		f[i] = min(f[i], f[i - 1] + 1);
	for (int i = n; i >= 1; i--)
		f[i] = min(f[i], f[i + 1] + 1);

	cout << *max_element(f + 1, f + n + 1);

}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/