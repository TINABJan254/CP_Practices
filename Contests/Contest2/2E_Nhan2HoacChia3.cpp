#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
int main(){
	int n; cin >> n;
	int a[n+1];
	for(int i =1; i <=n; i++) cin >> a[i];
	
	ll res = 0;
	for(int i =1; i <=n; i++){
		while(a[i] % 2 == 0){
			res++;
			a[i] /= 2;
		}
	}
	cout << res << endl;
	return 0;
}
/*
Cho dãy số A[] có N phần tử. Mỗi bước biến đổi, bạn cần thực hiện một trong hai loại thao tác sau lên các phần tử A[i]: (1) nhân A[i] với 3, hoặc (2) lấy A[i] chia cho 2.

Phép chia được thực hiện khi và chỉ khi A[i] là một số chẵn. Tại mỗi bước, không được phép thực hiện duy nhất thao tác (1) lên cả N phần tử.

Nhiệm vụ của bạn là hãy xác định xem số lượng bước biến đổi có thể được thực hiện lớn nhất bằng bao nhiêu?

Input:

Dòng đầu tiên là số nguyên dương N (1 ≤ N ≤ 10000).

Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 109).

Output: 

In ra đáp án là mức năng lượng tìm được.

Test ví dụ:

Input
3
5 2 4
Output
3

Input
4
1 3 5 7
Output
0

Input
6
242 192 333 169 256 192
output
21

*/