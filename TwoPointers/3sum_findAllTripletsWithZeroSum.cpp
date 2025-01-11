//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    vector<vector<int>> findTriplets(vector<int> &arr) {
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < arr.size(); i++){
            for (int j = i + 1; j < arr.size(); j++){
                mp[arr[i] + arr[j]].push_back({i, j});
            }
        }
        
        set<vector<int>> st;
        for (int i = 0; i < arr.size(); i++){
            int req = -arr[i];
            for (auto it : mp[req]){
                if (i != it.first && i != it.second){;
                    vector<int> tmp = {i, it.first, it.second};
                    sort(tmp.begin(), tmp.end());
                    st.insert(tmp);
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
3 sum bản khó với các ptử ko phân biệt
https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/