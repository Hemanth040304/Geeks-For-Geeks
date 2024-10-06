//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), count = 0;
        queue<pair<int, int>> q;
        
        int row[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int col[8] = {0, 0, -1, 1, -1, 1, 1, -1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    q.push({i,j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        int i = q.front().first, j = q.front().second;
                        q.pop();
                        for (int k = 0; k < 8; k++) {
                            int new_i = i + row[k], new_j = j + col[k];
                            if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == '1'){
                                q.push({new_i, new_j});
                                grid[new_i][new_j] = '0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends