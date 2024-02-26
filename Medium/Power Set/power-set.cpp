//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	    void Helper(int ind, vector<string> &ans, string &s, string ds){
	        if(ind == s.size()){
	            ans.emplace_back(ds);
	            return ;
	        }
	        ds += s[ind];
	        Helper(ind + 1, ans, s, ds);
	        ds.pop_back();
	        Helper(ind + 1, ans, s, ds);
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		   vector<string> ans;
		   Helper(0,ans,s,"");
		   sort(ans.begin(), ans.end());
		   ans.erase(ans.begin(),ans.begin()+1);
		   return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends