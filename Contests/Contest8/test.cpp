#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query {
    int L, R, idx;
};

// Biến toàn cục
const int MAXN = 500005;
int N, Q;
int A[MAXN], answer[MAXN];
int freq[MAXN];  // Tần suất xuất hiện của các phần tử
int currentDistinct = 0;

// Hàm thêm một phần tử vào đoạn hiện tại
void add(int x) {
    freq[x]++;
    if (freq[x] == 1) {
        currentDistinct++;
    }
}

// Hàm xóa một phần tử khỏi đoạn hiện tại
void remove(int x) {
    if (freq[x] == 1) {
        currentDistinct--;
    }
    freq[x]--;
}

// Mo's Algorithm để xử lý các truy vấn
void moAlgorithm(vector<Query>& queries) {
    int block_size = sqrt(N);  // Kích thước mỗi khối
    sort(queries.begin(), queries.end(), [block_size](Query a, Query b) {
        if (a.L / block_size != b.L / block_size)
            return a.L / block_size < b.L / block_size;
        return a.R < b.R;
    });

    int L = 1, R = 0;
    for (Query q : queries) {
        while (R < q.R) add(A[++R]);
        while (R > q.R) remove(A[R--]);
        while (L < q.L) remove(A[L++]);
        while (L > q.L) add(A[--L]);
        answer[q.idx] = currentDistinct;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    // Nhập dữ liệu
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].idx = i;
    }

    // Gọi hàm Mo's Algorithm để xử lý các truy vấn
    moAlgorithm(queries);

    // Xuất kết quả
    for (int i = 0; i < Q; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}
