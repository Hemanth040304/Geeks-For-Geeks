//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int zc=-1,oc=-1,tc=-1;
        int ans=INT_MAX;
        int i=0,j=0;
        int m=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                zc=i;
            }
            else if(s[i]=='1')
            {
                oc=i;
            }
            else if(s[i]=='2')
            {
                tc=i;
            }
        if(zc!=-1 and oc!=-1 and tc!=-1)
        {
            int ma=max(oc,max(zc,tc));
            int mi=min(oc,min(zc,tc));
            ans=min(ans,ma-mi+1);
        }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends