//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        vector<int> ans;
        int zero = 0, n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1] and arr[i] != 0) {
                ans.emplace_back(arr[i] * 2);
                arr[i + 1] = 0;
            }
            else if (arr[i] == 0) zero++;
            else ans.emplace_back(arr[i]);
        }
        ans.emplace_back(arr[n - 1]);
        
        while (zero--) {
            ans.emplace_back(0);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends