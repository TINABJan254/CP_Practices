#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

void minLeft(int a[], int n, int left[]){
	stack<int> st;
	for(int i =1; i <=n; i++){
		while(!st.empty() && a[i] >= a[st.top()]){
			st.pop();
		}
		if(st.empty()) left[i] = 1; //phan tu thoa man c >= Xl
		st.push(i);
	}
}

void maxRight(int a[], int n, int right[]){
	stack<int> st;
	for(int i =n; i >=1; i--){
		while(!st.empty() && a[i] < a[st.top()]){
			st.pop();
		}
		if(st.empty()) right[i] = 1; //phan tu thoa man p < Xr
		st.push(i);
	}
}
int main(){
	int n; cin >> n;
	int a[n+1];
	for(int i =1; i <=n; i++) cin >> a[i];
	int left[n+1] = {0}, right[n+1] = {0};
	
	minLeft(a, n, left);
	maxRight(a, n, right);
	
	vector<int> v;
	for(int i =1; i <=n; i++){
		if(left[i] == 1 && right[i] == 1){
			v.push_back(a[i]);
		}
	}
	cout << v.size() << " ";
	int end = min((int)v.size(), 100);
	for(int i =0; i < end; i++){
		cout << v[i] << " ";
	}
	return 0;
}