#include<bits/stdc++.h>
using namespace std;

set<long long>se;
void ql(string x,int i,int j){
	if(x!="")se.insert(stoll(x));
	if(x.size()==10)return;
	else{
		ql(x+to_string(i),i,j);
		ql(x+to_string(j),i,j);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			if(i!=j)ql("",i,j);
		}
	}
	int ans=0;
	for(long long x:se){
		if(x<=n)ans++;
	}
	cout<<ans-1;
}

/*
Cho một số nguyên dương N, hãy đếm xem có bao nhiêu số nguyên dương trong đoạn [1, N] 
có biểu diễn thập phân gồm không quá 2 chữ số.

Input:

Một số nguyên dương N duy nhất (1 ≤ N ≤ 10^9).

Output:

In ra một số nguyên duy nhất là đáp án của bài toán.

Test ví dụ:

Input			   Ouput
10 					10
105 				101
356					175
Giải thích test 2: Có 4 số không thỏa mãn là 102, 103, 104, 105.
*/