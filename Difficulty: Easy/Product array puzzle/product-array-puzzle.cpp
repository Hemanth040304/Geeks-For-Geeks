//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
    
        long long product = 1;
        int zeroCount = 0;
    
        for (long long num : nums) {
            if (num == 0) zeroCount++;
            else product *= num;
        }
    
        for (int i = 0; i < n; ++i) {
            if (zeroCount > 1) result[i] = 0;
            else if (zeroCount == 1) 
                if (nums[i] == 0) result[i] = product;
                else result[i] = 0;
            else result[i] = product / nums[i];
        }
    
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends