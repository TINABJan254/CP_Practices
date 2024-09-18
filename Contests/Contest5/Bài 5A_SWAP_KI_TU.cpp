#include<bits/stdc++.h>
using namespace std;

bool solve(string a, string b) {
    unordered_map<char, char> mp1, mp2;
    
    for(int i = 0; i < a.size(); i++) {
        char x = a[i], y = b[i];
        if(mp1.find(x) != mp1.end()) {
            if(mp1[x] != y)
                return false;
        } 
		else {
            mp1[x] = y;
        }
        
        if(mp2.find(y) != mp2.end()) {
            if(mp2[y] != x)
                return false;
        } 
		else {
            mp2[y] = x;
        }
    }
    
    return true;
}

int main() {
    string a, b; 
    cin >> a >> b;
    
    if(solve(a, b)) 
        cout << "Yes\n";
    else 
        cout << "No\n";
        
    return 0;
}

