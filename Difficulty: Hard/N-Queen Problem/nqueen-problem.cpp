//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int check(int row, int col, vector<string> v) {
        int i = row, j = col;
        while (i != -1 and j != -1){
            if (v[i][j] == 'Q') return 0;
            i--;
            j--;
        }
        
        i = row, j = col;
        while (j >= 0){
            if(v[i][j] == 'Q') return 0;
            j--;
        }
        
        i = row, j = col;
        while (i >= 0){
            if(v[i][j] == 'Q') return 0;
            i--;
        }
        
        while (row >= 0 and col < v.size()) {
            if(v[row][col] == 'Q') return 0;
            row--;
            col++;
        }
        return 1;
    }
    void Print(int rem, int row, int n, vector<string> &v, vector<vector<int>> &ans) {
        if(!rem){
            vector<int>g;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(v[i][j] == 'Q') g.emplace_back(j + 1);
                }
            }
            ans.emplace_back(g);
            return ;
        }
        for(int i = 0; i < n; i++){
            if(check(row, i, v)) {
                v[row][i] = 'Q';
                Print(rem - 1, row + 1, n, v, ans);
                v[row][i] = '.';
            }
        }
    }
    vector<vector<int>> ans;
    vector<vector<int>> nQueen(int n) {
        string s(n, '.');
        vector<string> v(n, s);
        Print(n, 0, n, v, ans);
        return ans;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends