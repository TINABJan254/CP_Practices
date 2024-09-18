#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M;

    long long d = M / N; // d là ước lớn nhất ban đầu
    while (M % d != 0) {
        d--;
    }

    cout << d << endl;
    return 0;
}