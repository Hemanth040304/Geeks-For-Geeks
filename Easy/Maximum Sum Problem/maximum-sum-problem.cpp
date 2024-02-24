//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        
        int Caller(int n, int dp[]){
            if(n / 2 + n / 3 + n / 4 <= n) return n;
            if(dp[n] != -1) return dp[n];
            return dp[n] = Caller(n / 2, dp) + Caller(n / 3, dp) + Caller(n / 4, dp);
        }
    
        int maxSum(int n){
            //code here.
            int dp[n+1];
            memset(dp, -1, sizeof(dp));
            return Caller(n, dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends