//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool pal(vector<int> p){
        vector<int> x = p;
        reverse(x.begin(), x.end());
        return p == x;
    }
    
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        string ans = "";
        int n = arr.size(), m = arr[0].size();
        
        for (int i = 0; i < n; i++) {
            vector<int> p = arr[i];
            if(pal(p)){
                ans = ans + to_string(i);
                ans = ans + " R";
                return ans;
            }
        }
        
        for (int j  = 0; j < m; j++) {
            vector<int> p;
            int x = j;
            for (int i = 0; i < n; i++) {
                p.emplace_back(arr[i][j]);
            }
            if(pal(p)){
                ans = ans + to_string(x);
                ans = ans + " C";
                return ans;
            }
            p.empty();
        }
        
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends