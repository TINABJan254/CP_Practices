#include <bits/stdc++.h>
using namespace std;

set<int> se; // Tập hợp các giá trị duy nhất trong dãy A
map<int, int> mp; // Bản đồ lưu tần suất xuất hiện của các phần tử

// Kiểm tra xem A[i] có thỏa mãn điều kiện không
bool check(int n) {
    if(n == 1) return true;
    if(se.find(1) != se.end()) return false; // Nếu có 1 thì tất cả các số khác đều không hợp lệ
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            // Nếu ước hoặc thương của n có trong se thì n không hợp lệ
            if(se.find(i) != se.end() || se.find(n / i) != se.end()) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n; 
    cin >> n;
    int a[n+1];

    // Đọc dữ liệu và lưu vào set và map
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        se.insert(a[i]); // Thêm vào set
        mp[a[i]]++; // Tăng tần suất trong map
    }
    
    int cnt = 0; // Đếm số phần tử thỏa mãn điều kiện
    
    for(auto x : mp) {
        if(x.second == 1 && check(x.first)) cnt++; // Nếu phần tử duy nhất và thỏa mãn điều kiện
    }
    
    cout << cnt << endl; // In ra kết quả
}
