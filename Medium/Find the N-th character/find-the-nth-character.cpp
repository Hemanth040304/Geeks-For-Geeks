//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    void FinalAns(char s, int r, int n, string &ans) {
        if(r <= 0 or ans.size() > n) return;
        if(s == '1'){
            FinalAns('1', r - 1, n, ans);
            FinalAns('0', r - 1, n, ans);
            if(r == 1) {
                ans.push_back('1');
                ans.push_back('0');
            }
        }
        else{
            FinalAns('0', r - 1, n, ans);
            FinalAns('1', r - 1, n, ans);
            if(r == 1) {
                ans.push_back('0');
                ans.push_back('1');
            }
        }
    }
    
    char nthCharacter(string s, int r, int n) {
        //code here
        string ans;
        for (int i = 0; i < s.size(); i++) {
            FinalAns(s[i], r, n, ans);
            if(ans.size() > n) break;
        }
        return ans[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends