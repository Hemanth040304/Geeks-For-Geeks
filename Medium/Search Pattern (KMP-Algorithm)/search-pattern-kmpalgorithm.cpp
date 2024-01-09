//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int>ans;
            ans.emplace_back(-1);
            int txt_len = txt.size();
            int pat_len = pat.size();
            for(int i = 0 , j = pat_len-1 ; j < txt_len ; i++,j++){
                int c=0;
                for(int x = i, y = 0 ; x <= j ; x++,y++){
                    if(txt[x]==pat[y])c++;
                    else break;
                }
                if(c==pat_len){
                    if(ans[0]==-1)ans[0] = i + 1;
                    else ans.emplace_back(i+1);
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
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends