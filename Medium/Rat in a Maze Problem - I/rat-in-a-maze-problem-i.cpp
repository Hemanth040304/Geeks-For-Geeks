//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void call(int i, int j, int &n, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<string>&ans, string s){
        if(i==n-1 and j==n-1){
            if(grid[n-1][n-1]==1)
                ans.emplace_back(s);
            return;
        }
        if(i>=0 and i<n and j>=0 and j<n and !vis[i][j] and grid[i][j]){
            if(i-1>=0 and i-1<n  and grid[i-1][j] and !vis[i-1][j]){
                s+='U';
                vis[i][j]=1;
                call(i-1,j,n,grid,vis,ans,s);
                vis[i][j]=0;
                s.pop_back();
            }
            if( j+1>=0 and j+1<n and grid[i][j+1] and !vis[i][j+1]){
                s+='R';
                vis[i][j]=1;
                call(i,j+1,n,grid,vis,ans,s);
                vis[i][j]=0;
                s.pop_back();
            }
            if(i+1>=0 and i+1<n  and grid[i+1][j] and !vis[i+1][j]){
                s+='D';
                vis[i][j]=1;
                call(i+1,j,n,grid,vis,ans,s);
                vis[i][j]=0;
                s.pop_back();
            }
            if(j-1>=0 and j-1<n and grid[i][j-1] and !vis[i][j-1]){
                s+='L';
                vis[i][j]=1;
                call(i,j-1,n,grid,vis,ans,s);
                vis[i][j]=0;
                s.pop_back();
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        call(0,0,n,m,vis,ans,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends