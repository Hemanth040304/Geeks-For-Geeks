//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution {
  public:
    void perm(vector<int>arr,vector<int>&dp,vector<vector<int>>&res,vector<int>&vis,int n){
        if(dp.size()==n){
            res.push_back(dp);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dp.push_back(arr[i]);
                vis[i]=1;
                perm(arr,dp,res,vis,n);
                vis[i]=0;
                dp.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<int>vis(n,0);
        vector<vector<int>>res;
        vector<int>dp;
        perm(arr,dp,res,vis,n);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends