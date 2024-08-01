#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int charToInt(char c){
	return (c - '0');
}

string add(string a, string b){
	if (a.sz < b.sz)
		swap(a, b);
	int lena = a.sz, lenb = b.sz;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	b += string(lena - lenb, '0');
	string res = "";
	int carry = 0;
	for (int i = 0; i < lena; i++){
		int tmp = charToInt(a[i]) + charToInt(b[i]) + carry; 
		res += (char)(tmp % 10 + '0');
		carry = tmp / 10;
	}
	if (carry){
		res += (char)(carry + '0');
	}
	reverse(res.begin(), res.end());
	return res;
}

bool isLessThan(string a, string b){
	if (a.sz != b.sz){
		if (a.sz < b.sz)
			return true;
		return false;
	}
	return a < b;
}

void solve(){
	int n; cin >> n;
	vector<string> a(n);
	for (string &x : a) cin >> x;
	stack<string> st;
	for (string x : a){
		while (!st.empty() && isLessThan(st.top(), x)) st.pop();
		while (!st.empty() && st.top() == x){
			st.pop();
			x = add(x, x);
		}
		st.push(x);
	}

	while (st.sz > 1) st.pop();
	cout << st.top() << EL;
}

void local(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
}

int main(){
	local();
	faster();
	solve();
	return 0;
}
/*

*/