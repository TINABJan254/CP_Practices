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
	for (int i = 0; i < n; i++){
		cin >> a[i];
		while (a[i] % 2 == 0) a[i] /= 2;
		while (a[i] % 3 == 0) a[i] /= 3;
	}

	for (int i = 1; i < n; i++)
		if (a[i] != a[0]){
			cout << "No";
			return;
		}
	cout << "Yes";
}

int main(){
	faster();
	solve();
	return 0;
}

/*
  Mỗi số đều có thể phân tích thành các tsnt: 2^p1 * 3^p2 * 5^p3 * 7^p4...
  Ta sẽ đi chia Ai cho 2 và 3 nhiều nhất có thể
  Cuối cùng nếu tất cả các số trong dãy a bằng nhau thì dãy đó thỏa mãn
  VÌ SAO khi chia cho 2 và 3 về cùng 1 số thì có thể nhân cho 2 và 3 để tạo thành
cùng một số
	Giả sử Ai và Aj khi chia cho 2 và 3 thì được cùng 1 số
	ta có: Ai = x * 2^p1 * 2^p2
		   Aj = x * 2^p3 * 2^p4
		Ta thấy Ai và Aj có phần x bằng nhau chỉ khác nhau số các thừa số 2 và 3
	  vậy ta có thể tinh chỉnh số các thừa số 2 và 3 để cho Ai va Aj trở nên bằng nhau

https://codeforces.com/contest/574/problem/C
*/