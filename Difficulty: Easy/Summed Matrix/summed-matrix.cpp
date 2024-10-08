//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q < 2 || q > n * 2) return 0;
        if(q == 2 || n * 2 == q) return 1;
        if(n * 2 / 2 == q) return n;
        if(n * 2 / 2 + 1 >= q) return q - 1;
        else return n * 2 - q + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends