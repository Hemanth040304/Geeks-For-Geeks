//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        
        int x[4] = {0, -1, 1, 0};
        int y[4] = {1, 0, 0, -1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    for (int f = 0; f < 4; f++){
                        int q = i + x[f];
                        int w = j + y[f];
                        if(q >= 0 and q < n and w >= 0 and w < m){
                            if (matrix[q][w] == 1) ans++;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends