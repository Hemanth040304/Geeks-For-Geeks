//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n + 1, -1);
        
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        
        for (int i = 2; i <= n; i++) {
            int a = dp[i - 1] + abs(height[i] - height[i - 1]);
            int b = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(a, b);
        }
        
        
        return dp[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends