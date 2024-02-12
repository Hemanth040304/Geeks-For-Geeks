//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans = 0;
        long long mod = 1000000007;
        long long num = 1;
        for(int i = 1 ; i <= n ; i++){
            long long dup = 1;
            for(int j = 1 ; j <= i ; j++){
                dup *= num;
                dup %= mod;
                num++;
            }
            ans += dup;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends