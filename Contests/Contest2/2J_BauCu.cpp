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

bool cmp(pii a, pii b){
    if (a.se != b.se)
        return a.se > b.se;
    return a.fi < b.fi;
}

void solve(){
    int n, m; cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    vector<pii> v;
    for (auto it = mp.begin(); it != mp.end(); it++){
        v.pb({it->fi, it->se});
    }

    sort(v.begin(), v.end(), cmp);

    if (v[0].se == v[v.sz - 1].se){
        cout << "NONE";
    }
    else{
        int i = 0;
        while (v[i].se == v[i + 1].se){
            ++i;
        }
        cout << v[i + 1].fi;
    }
}

int main(){
    faster();
    solve();
    return 0;
}

/*
Khu dân cư ABC tiến hành bầu tổ trưởng dân phố. Có M ứng viên và N cử tri. 
Người dân trong khu dân cư đã chán ngấy với việc các ứng viên vận động tranh cử, 
câu kéo phiếu bầu trong các nhiệm kỳ trước nên họ quyết định đặt ra quy định mới 
như sau:

Các ứng viên được đánh số từ 1 tới M. Mỗi cử tri sẽ viết ra đúng 1 số thứ tự ứng 
viên mình muốn chọn và bỏ vào hòm phiếu.
Người trúng cử là người có số phiếu bầu nhiều thứ hai
Nếu không có người đứng thứ hai thì kết quả bầu cử sẽ bị hủy bỏ
Nếu có nhiều hơn 1 người cùng có số phiếu nhiều thứ hai thì người nào có số thứ tự 
nhỏ nhất sẽ được chọn.
Viết chương trình xác định người trúng cử.

Input

Dòng đầu ghi hai số N và M (1 < M < 10, 5 < N < 500).

Dòng thứ 2 ghi N giá trị trong các phiếu bầu. Các giá trị đảm bảo hợp lệ (tức là từ 1 đến M).

Output

Ghi ra số thứ tự của người trúng cử.

Hoặc nếu không có ai trúng cử thì ghi ra NONE

Ví dụ
Input
10 4
2 3 1 2 3 4 1 2 3 2

Output
3

Input
8 4
1 2 3 4 4 3 2 1

Output
NONE
*/