//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    int n = mat.size(), m = mat[0].size();
    
    for(int i = 0; i < n; i++){
        int x = i, y = 0, val = mat[x][y];
        while(x >= 0 and x < n and y >= 0 and y < m){
            if(val != mat[x][y]) return false;
            x++;
            y++;
        }
    }
    
    for(int j = 0; j < m; j++){
        int x = 0, y = j, val = mat[x][y];
        while(x >= 0 and x < n and y >= 0 and y < m){
            if(val != mat[x][y]) return false;
            x++;
            y++;
        }
    }
}