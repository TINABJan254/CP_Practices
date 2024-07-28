#include<bits/stdc++.h>
using namespace std;

int n; int x[20];
bool isFinish;

void Init(){
	x[1] = 1;
	for(int i =2; i <=n; i++){
		x[i] = 0;
	}
}
//sinh ra tất cả xâu nhị phân 0 1
void Sinh(){
	int idx = n;
	while(idx >=1 && x[idx] == 1){
		x[idx] = 0;
		idx--;
	}
	if(idx == 0) isFinish = true;
	else x[idx] = 1;
}

int main(){
	Init();
	cin >> n;
	int a[n+1];
	int sum = 0;
	for(int i =1; i <=n; i++){
		cin >> a[i];
		sum += a[i];
	}

	set<int> se;
	isFinish = false;
	while(!isFinish){
		int F1[sum+1] = {0}; 
		int F0[sum+1] = {0};
		F1[0] = 1; F0[0] = 1;
		
		for(int i =1; i <=n; i++){
			for(int j =sum; j >=a[i]; j--){
				if(x[i] == 0) F0[j] = max(F0[j], F0[j - a[i]]);
				else F1[j] = max(F1[j], F1[j - a[i]]);
			}
		}
		for(int i =1; i <=sum; i++){
			if(F0[i] == F1[i] && F0[i] == 1) se.insert(i);
		}
		Sinh();
	}
	if(se.empty()) cout << 0;
	else{
		cout << se.size() << endl;
		for(auto x : se) cout << x << " ";
	}
	return 0;
}

/*
Cho dãy số A[] với N số nguyên phân biệt. 

Hãy tìm tất cả các số nguyên X sao cho tồn tại 2 tập con không giao nhau trong dãy A[] mà tổng các phần tử trong mỗi tập đó bằng X. 

Một tập con của một dãy số được tạo ra bằng các loại bỏ một số phần từ (không loại bỏ tất cả) trong dãy số ban đầu.

Dãy số ban đầu cũng được coi là tập con của chính nó (tức là không loại bỏ phần tử nào). . 

Input:

Dòng đầu ghi số N là số phần tử của dãy số A[]. (1 ≤ N ≤ 18).
Dòng số 2 ghi N số nguyên phân biệt  A1; A2; …; AN (1 ≤ Ai ≤ 30).
 

Output:

Dòng đầu tiên ghi số m là số lượng giá trị X tìm được.
Dòng thứ 2 lần lượt ghi các giá trị X theo thứ tự từ nhỏ đến lớn.

Input
4
1 3 4 2
Output
3
3 4 5

IN
1
4
OUt
0
*/