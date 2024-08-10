//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void dfs(int i, int j, vector<vector<int>> &A) {
        int m = A.size(), n = A[0].size();
        if (i < 0 or i >= m or j < 0 or j >= n or A[i][j] != 1) return;

        A[i][j] = 0;

        dfs(i + 1, j, A);
        dfs(i, j + 1, A);
        dfs(i - 1, j, A);
        dfs(i, j - 1, A);
    }

public:
    int numberOfEnclaves(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            if (A[i][0]) dfs(i, 0, A);
            if (A[i][n - 1]) dfs(i, n - 1, A);
        }
        
        for (int j = 1; j < n - 1; j++) {
            if (A[0][j]) dfs(0, j, A);
            if (A[m - 1][j]) dfs(m - 1, j, A);
        }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (A[i][j]) count++;
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends