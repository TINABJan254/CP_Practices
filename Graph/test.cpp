#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    unordered_map<int, int> count;
    for (int num : A) {
        count[num]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& pair : count) {
        pq.push(pair.first);
    }

    while (pq.size() > 1) {
        int smallest = pq.top();
        pq.pop();
        if (count[smallest] > 1) {
            int new_num = smallest * 2;
            count[smallest] -= 2;
            count[new_num]++;
            pq.push(new_num);
        }
        if (count[smallest] > 0) {
            pq.push(smallest);
        }
    }

    cout << pq.top() << endl;
}

int main() {
    solve();
    return 0;
}
