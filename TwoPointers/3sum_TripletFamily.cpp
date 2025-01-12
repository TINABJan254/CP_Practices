//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= 0; i--){
            int l = 0, r = i - 1;
            while (l < r){
                if (arr[i] == arr[l] + arr[r]){
                    return true;
                }
                
                if (arr[l] + arr[r] > arr[i]){
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return false; 
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
3sum: bản dễ, với các ptử pbiệt, chú ý ở phần sort desc
*/