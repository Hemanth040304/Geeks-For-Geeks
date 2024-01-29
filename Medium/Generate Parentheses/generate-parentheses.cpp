//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void fun(vector<string> &ans, int n, int open, int close, string s){
        if(open<close or (open==n and close==n)){
            ans.emplace_back(s);
            return;
        }
        if(open<n){
            s+='(';
            fun(ans,n,open+1,close,s);
            s.pop_back();
        }
        if(close<n and close<open){
            s+=')';
            fun(ans,n,open,close+1,s);
            s.pop_back();
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        fun(ans,n,0,0,"");
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends