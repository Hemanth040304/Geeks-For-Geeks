//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       long long mod = 1000000007;
       vector<int> ans(n + 1, 1);
       for(int i = 3; i <= n; i++){
           ans[i] = (ans[i - 2] + ans[i - 3]) % mod;
       }
       return ans[n];
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends