//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int N) {
        // code here
        int Bit[8] = {0};
        
        for(int i = 7 ; i > -1 ; i--) 
            Bit[i] = ((N>>i)&1);
        
        for(int i = 0 , j = 4 ; j < 8 ; i++ , j++)
            swap(Bit[i],Bit[j]);
        
        int k=0;
        
        for(int i = 7 ; i > -1 ; i--)
            if(Bit[i])
                k += pow(2,i);
        
        return k;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends