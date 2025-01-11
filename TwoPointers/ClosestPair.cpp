#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int j = m-1, i = 0;
        int diff = INT_MAX;
        int c1 = 0, c2 = 0;
        while (i < n && j >= 0){
            if (abs(arr[i] + brr[j] - x) < diff){
                diff = abs(arr[i] + brr[j] - x);
                c1 = arr[i];
                c2 = brr[j];
            }
            
            if (arr[i] + brr[j] > x){
                --j;
            } else {
                ++i;
            }
            
        }
        return {c1, c2};
        // {} ktao 1 vector, array, pair, obect, primitive-variable
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    
    cout << "~" << "\n";
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1?itm_source=geeksforgeeks
*/