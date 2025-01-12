//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 2; i++){
            int l = i + 1, r = arr.size() - 1;
            int reqSum = target - arr[i];
            while (l < r){
                if (arr[l] + arr[r] == reqSum){
                    return true;
                }
                
                if (arr[l] + arr[r] < reqSum){
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        bool result = solution.hasTripletSum(arr, target);
        cout << (result ? "true" : "false") << "\n";
    }

    return 0;
}
// } Driver Code Ends

/*
3 sum bản dễ: các ptử phân biệt, chỉ cần kiểm tra tồn tại hay không
*/