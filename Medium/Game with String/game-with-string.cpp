//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int ans = 0;
        map<char,int>mp;
        for (auto it : s) {
            mp[it]++;
        }
        
        priority_queue<int>q;
        
        for(auto it : mp){
            q.push(it.second);
        }
        while(k--){
            int a = q.top();
            q.pop();
            a--;
            q.push(a);
        }
        
        while(!q.empty()){
            int x = q.top();
            ans += x * x;
            q.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends