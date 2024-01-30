//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        
        int dp[21][21][21];
        int fun(int i,int j, int k, int n, int m, int l, string &text1, string &text2, string &text3){
        if(i>=n || j>=m || k>=l)return 0;
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        
        int cnt=0;
        if(text1[i]==text2[j] and text2[j]==text3[k]){
            cnt=1+fun(i+1,j+1,k+1,n,m,l,text1,text2,text3);
        }
        else{
            cnt=0+max(max(fun(i+1,j,k,n,m,l,text1,text2,text3),fun(i,j+1,k,n,m,l,text1,text2,text3)),fun(i,j,k+1,n,m,l,text1,text2,text3));
        }
        return dp[i][j][k]=cnt;
    }

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            memset(dp,-1,sizeof(dp));
            return fun(0,0,0,n1,n2,n3,A,B,C);
        }
};



//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends