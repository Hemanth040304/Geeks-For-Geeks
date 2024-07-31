//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans = "";
        string m = *min_element(arr.begin(), arr.end());
        int n = arr.size();
        
        for (int j = 0; j < m.size(); j++) {
            char current_char = m[j];
            for (const auto& str : arr) {
                if (str[j] != current_char) {
                    if (ans.size() != 0) return ans;
                    else return "-1";
                }
            }
            ans += current_char;
        } 
        
        if (ans.size() != 0) return ans;
        else return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends