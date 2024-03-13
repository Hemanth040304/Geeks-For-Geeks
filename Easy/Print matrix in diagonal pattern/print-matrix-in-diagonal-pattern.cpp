//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        int n = mat.size();
        int index = 0;
        vector<int>ans(n*n);
        int row = 0, col = 0;
        bool up = true;
        
        while(row < n and col < n){
            if(up){
                while(row > 0 and col < n - 1){
                    ans[index] = mat[row][col];
                    row--;
                    col++;
                    index++;
                }
                ans[index++] = mat[row][col];
                if(col == n - 1) row++;
                else col++;
            }
            else{
                while(row < n - 1 and col > 0){
                    ans[index] = mat[row][col];
                    row++;
                    col--;
                    index++;
                }
                ans[index++] = mat[row][col];
                if(row == n - 1) col++;
                else row++;
            }
            up =! up;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends