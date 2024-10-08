//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
        vector <int> search(string pattern, string text){
            //code here.
            vector<int> ans;
            
            for (int i = 0; i <= text.size() - pattern.size(); i++){
                if(pattern[0] == text[i]){
                    string sub = text.substr(i,pattern.size());
                    if(sub == pattern) ans.emplace_back(i + 1);
                }
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends