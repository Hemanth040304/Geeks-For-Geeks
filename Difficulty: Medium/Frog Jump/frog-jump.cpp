//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int Love(int ind, vector<int> &height, vector<int> &dp) {
        if (ind <= 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        
        int oneStep = Love(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
        int twoStep = INT_MAX;
        if (ind > 1) twoStep = Love(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        
        return dp[ind] = min(oneStep, twoStep);
    }
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return Love(n - 1, height, dp);
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