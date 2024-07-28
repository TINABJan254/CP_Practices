#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	int tmp = 0; // lưu vị trí phần tử 1 (nhỏ nhất)
	int a[n+1]; 
	for(int i =1; i <=n; i++){
		cin >> a[i];
		if(a[i] == 1) tmp = i;
	}
	k = k - 1;
	int res = (n - tmp + k - 1) / k + (tmp - 1 + k -1) / k;
	cout << res << endl;
}

/*
Cho dãy số A[] có N phần tử là một hoán vị của 1, 2, 3, …, N. Bạn được phép thực hiện phép biến đổi sau: mỗi bước, chọn một đoạn K phần tử liên tiếp, sau đó gán giá trị của cả đoạn này bằng giá trị phần tử nhỏ nhất trong đoạn.

Các bạn hãy tính xem cần sử dụng ít nhất bao nhiêu phép biến đổi để có thể thu được một dãy số mới có tất cả các phần tử đều bằng nhau?

Input:

Dòng đầu tiên là số nguyên dương N và K (2 ≤ K ≤ N ≤ 100000).

Dòng tiếp theo là N số nguyên mô tả dãy số hoán vị A[].

Output: 

In ra một số nguyên là số bước đổi ít nhất cần thực hiện.

Test ví dụ:

Input
3 3
1 3 2
Ouput
1

In
4 3
2 3 1 4
Out
2

In
8 3
4 2 3 1 5 6 8 7
Out
4
*/

