//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool isPal(string s,int i, int n){
        if(i>=n)return 1;
        if(s[i]==s[n-1-i])return isPal(s,i+1,n);
        else return 0;
    }
    
    
    void fun(string &S, vector<vector<string>> &ans, int ind, int n, vector<string> &st){
        if(ind==n){
            ans.emplace_back(st);
            return;
        }
        for(int i = ind ; i < n ; i++){
            string str = S.substr(ind,i-ind+1);
            if(isPal(str,0,str.size())){
                st.emplace_back(str);
                fun(S,ans,i+1,n,st);
                st.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>>ans;
        vector<string>st;
        fun(S,ans,0,S.size(),st);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends