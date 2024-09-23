//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2);
        int n = arr.size();
        vector<int> freq(n + 1, 0);
    
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
    
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) ans[1] = i;
            if (freq[i] == 2) ans[0] = i;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends