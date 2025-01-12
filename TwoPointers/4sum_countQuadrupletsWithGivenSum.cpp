//{ Driver Code Starts

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countSum(vector<int>& arr, int target) {
        int res = 0;
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++){
            for (int k = i + 1; k < arr.size(); k++){
                res += mp[target - arr[i] - arr[k]];
            }
            
            // Lưu lại all tổng của cặp (i, j) với j < i để dùng sau này
            for (int j = 0; j < i; j++){
                mp[arr[i] + arr[j]] += 1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t-- > 0) {
        string input;
        getline(std::cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline character after reading k

        Solution solution;
        int ans = solution.countSum(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends

/*
4sum: bản medium
ở đây nguyên tắc bộ tứ với các chỉ số: j < i < k < l;
ta sẽ fix i (giả sử i luôn là index của ptử thứ 2 trong bộ tứ)
    tính tổng all cặp (j, i) với j < i => đã đạt yêu cầu j < i
    với vòng for tiếp theo, khi i đã tăng lên 1 (lớn hơn cái i cũ đã dùng tạo cặp với j)
        => công việc bây giờ là đi tìm k và l, ta lại tiếp tục fix i
            và đi xét all tổng cặp (i, k) với (i < k) => đảm bảo được i < k
            sau đó nếu tồn tại 1 cặp nào đó đã lưu trong map bằng target - a[i] - a[k] thì res += số cặp đó
https://www.geeksforgeeks.org/problems/count-quadruplets-with-given-sum/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/