#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n; ll k;
ll S[35], A[35];

char Find(int n, ll k){
	if(n == 0){
		if(k == 1) return 'a';
		return 'c';
	}
	else if(k == A[n]) return 'a';
	else if(k > S[n-1] + n+3) return Find(n-1, k - (S[n-1] + n+3));
	else if(k <A[n]) return Find(n-1, k);
	else return 'c';
}

int main(){
	//init
	S[0] = 3;
	A[0] = 1;
	for(int i =1; i <=30; i++){
		S[i] = 2*S[i-1] + (i+3); //Do dai xau i
		A[i] = S[i-1] + 1; //Vi tri chu A
	}
	//input
	cin >> k;
	int n = 0;
	while(S[n] < k){
		n++;
	}
	//solve
	cout << Find(n, k);
	return 0;
}
