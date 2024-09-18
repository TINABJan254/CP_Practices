#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

// Hàm so sánh để sắp xếp dựa trên (A[i] - B[i]) giảm dần
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.first - a.second) > (b.first - b.second);
}

int main() {
    int n; 
    cin >> n;
    vector<pair<ll, ll>> v(n);

    // Nhập dãy A
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
    }

    // Nhập dãy B
    for(int i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    // Sắp xếp các cặp (A[i], B[i]) dựa trên hiệu số (A[i] - B[i]) giảm dần
    sort(v.begin(), v.end(), cmp);

    ll sumA = 0, sumB = 0;
    ll cnt = 0;

    // Duyệt qua các phần tử đã sắp xếp để đếm số phần tử thỏa mãn điều kiện
    for(int i = 0; i < v.size(); i++) {
        sumA += v[i].first;  // Cộng dồn A[i]
        sumB += v[i].second; // Cộng dồn B[i]

        // Nếu sumA >= sumB, tăng số lượng phần tử thỏa mãn
        if(sumA >= sumB) {
            cnt++;
        } else {
            break; // Dừng lại nếu không còn thỏa mãn
        }
    }

    // In ra kết quả
    cout << cnt << endl;
}
