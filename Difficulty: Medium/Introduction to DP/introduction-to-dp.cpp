//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


#define ll long long

class Solution {
  public:
    int mod = 1000000007;
    vector<ll> tp;

    Solution() : tp(10001, -1) {}

    long long int topDown(int n) {
        // Top-down approach (Memoization)
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (tp[n] != -1) return tp[n];
        return tp[n] = ((topDown(n - 1) % mod) + (topDown(n - 2) % mod)) % mod;
    }

    long long int bottomUp(int n) {
        // Bottom-up approach (Tabulation)
        vector<ll> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        return dp[n];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends