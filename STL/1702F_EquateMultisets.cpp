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
	priority_queue<int> q1, q2;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		q1.push(x);
	}
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		q2.push(x);
	}	

	bool ok = true;
	while (!q2.empty()){
		int x1 = q1.top();
		int x2 = q2.top();
		if (x1 == x2){
			q1.pop();
			q2.pop();
		}
		else if (x2 > x1){
			q2.pop();
			q2.push( (int)(x2 / 2) );
		}
		else if (x2 < x1){
			//top a là số lẻ
			if (x1 % 2 != 0){
				ok = false;
				break;
			}
			q1.pop();
			q1.push( (int)(x1 / 2) );
		}
	}

	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";
}	
	
int main(){
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
https://codeforces.com/problemset/problem/1702/F
Nhận xét: chỉ cần dùng thao tác 2, thay vì nhân 2 ở thao mảng b, ta sẽ chia 2 ở
mảng a. Hơi hướng của bài Digital Logarithm
Trường hợp break: (res = NO) sẽ là TH mà top queue_a (tức số max mảng a) 
lớn hơn top queue_b + top queue_a là số lẻ.
	Số lẻ là ko được bởi vì top_queue_a > top_queue_b thì muốn tạo thành top_queue_a
	chỉ có cách là nhân 2 ở các số trong queue_b, mà một số bất kì nhân 2 lại là
	số chẵn, vậy nên ko thể tạo thành số lẻ được
*/