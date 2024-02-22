//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

int MOD = 1000000007;
int dp[1001][1001];
class Solution{
    public:
    
    int Helper(int ind, int n, int i, string &s, string &t, int tn){
        if(i >= tn) return 1;
        if(ind >= n) return 0;
        if(dp[ind][i] != -1) return dp[ind][i];
        if(s[ind] == t[i]) return dp[ind][i] = (Helper(ind + 1, n, i + 1, s, t, tn) + Helper(ind + 1, n, i, s, t, tn))  % MOD;
        else return dp[ind][i] = Helper(ind + 1, n, i , s, t, tn) % MOD;
    }
    
    int subsequenceCount(string s, string t){
        //Your code here
        memset(dp,-1,sizeof(dp));
        return Helper(0,s.size(),0,s,t,t.size()) % MOD;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends