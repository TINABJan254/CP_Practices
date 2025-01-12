//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1;
        int diff = INT_MAX;
        int c1 = -1, c2 = -1;
        while (l < r){
            if (abs(arr[l] + arr[r] - target) < diff){
                diff = abs(arr[l] + arr[r] - target);
                c1 = arr[l];
                c2 = arr[r];
            } else if (abs(arr[l] + arr[r] - target) == diff){
                if (abs(arr[l] - arr[r]) > abs(c1 - c2)){
                    c1 = arr[l];
                    c2 = arr[r];
                }
            }
            
            if (arr[l] + arr[r] < target){
                ++l;
            } else {
                --r;
            }
        }
        
        if (diff == INT_MAX){
            return {};
        }
        return {c1, c2};
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends

/*
2sum: bản trung bình, tìm các cặp gần bằng target, các ptử phân biệt
https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/