//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int k, int m, int n){
        if(n == 0) return 1;
        if(k > m) return 0;
        return fun(k*2,m,n-1) + fun(k+1,m,n);
    }
    int numberSequence(int m, int n){
        // code here
        return fun(1,m,n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends