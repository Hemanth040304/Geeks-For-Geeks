//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
private:
    void path(int i, int j, int n, int m, vector<vector<int>> &mat, vector<string> &ans, string s, vector<vector<int>> &vis) {
        if (i < 0 or j < 0 or i >= n or j >= m or mat[i][j] == 0 or vis[i][j] == 1) return;
        
        if (i == n - 1 && j == m - 1) {
            ans.emplace_back(s);
            return;
        }
        
        vis[i][j] = 1;
        path(i - 1, j, n, m, mat, ans, s + 'U', vis);
        path(i, j + 1, n, m, mat, ans, s + 'R', vis);
        path(i + 1, j, n, m, mat, ans, s + 'D', vis);
        path(i, j - 1, n, m, mat, ans, s + 'L', vis);
        vis[i][j] = 0;
    }
    
public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        path(0, 0, n, m, mat, ans, "", vis);
        
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends