#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef pair<vector<int>, int> pvii;

int n;
vector<int> v; // lưu hoán vị p

bool checkFinish(vector<int> v){
	for(int i =1; i <=2*n; i++){
		if(v[i] < v[i-1]) return false;
	}
	return true;
}

vector<int> thaotac1(vector<int> &tmp){
	vector<int> next_1 = tmp;
	for(int i =1; i <=2*n-1; i +=2){
		swap(next_1[i], next_1[i+1]);
	}
	return next_1;
}

vector<int> thaotac2(vector<int> &tmp){
	vector<int> next_2 = tmp;
	for(int i =1; i <=n; i++){
		swap(next_2[i], next_2[n+i]);
	}
	return next_2;
}
void BFS(){
	queue<pvii> Q; 
	set<vector<int>> se; 
	Q.push({v, 0});
	//<hoán vị hiện tại, số bước>
	se.insert(v);
	
	while(!Q.empty()){
		auto top = Q.front(); Q.pop();
		vector<int> current = top.fi; 
		int cur_cnt = top.se;
//		
//		for(auto x : current) cout << x << " ";
//		cout << endl;
//		
		if(checkFinish(current)){ //nếu P tăng dần in ra số bước
			cout << cur_cnt;
			return;
		}
		
		auto next_1 = thaotac1(current); 
		auto next_2 = thaotac2(current);
		
		if(se.find(next_1) == se.end()){ 
			Q.push({next_1, cur_cnt + 1});
			se.insert(next_1);
		}
		if(se.find(next_2) == se.end()){
			Q.push({next_2, cur_cnt + 1});
			se.insert(next_2);
		}
	}
	cout << -1;
	return;
}
int main(){
	v.clear();
	cin >> n;
	v.pb(0);
	for(int i =1; i <=2*n; i++){
		int x; cin >> x;
		v.pb(x);
	}
	BFS();
}
/*
Cho số nguyên N và một hoán vị P[] có độ dài 2N, gồm các phần tử 
{1, 2, …, 2N-1, 2N}. Có 2 loại thao tác:

Đổi chỗ các phần tử P[1] vs P[2], P[3] vs P[4], …, P[2N-1] vs P[N].
Đổi chỗ các phần tử P[1] vs P[N+1], P[2] vs P[N+2], …, P[N] vs P[2N].
Nhiệm vụ của bạn là hãy sử dụng ít phép biến đổi nhất để đưa hoán vị P[] 
ban đầu về thành một dãy số tăng dần.

Input: 

Dòng đầu tiên là số nguyên N (1 ≤ N ≤ 1000).

Dòng tiếp theo gồm 2N số nguyên P[i] mô tả một dãy hoán vị.

Output: 

In ra số thao tác ít nhất cần sử dụng. Nếu không tìm được đáp án, hãy in ra -1.

Test ví dụ:

Input:													
3
6 3 2 5 4 1
Output:
3

Input
2
3 4 2 1
Output
-1
Input
3
1 2 3 4 5 6
Output
0
*/
