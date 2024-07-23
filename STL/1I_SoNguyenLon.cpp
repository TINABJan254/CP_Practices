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

string u = to_string(LLONG_MAX);
string d = to_string(INT_MAX);

bool check(string s){
    for (int i = 0; i < s.sz; i++){
        if (isalpha(s[i]))
            return false;
    }
    if (s.sz < d.sz || s.sz > u.sz)
        return false;
    if (s.sz == d.sz && s <= d)
        return false;
    if (s.sz == u.sz && s > u)
        return false;
    return true;
}

void solve(){
    string s;
    long long sum = 0;
    while (cin >> s){
        if (check(s))
            sum += stoll(s);
    }
    cout << sum << EL;
}

int main(){
	faster();
    solve();
}

/*

*/	