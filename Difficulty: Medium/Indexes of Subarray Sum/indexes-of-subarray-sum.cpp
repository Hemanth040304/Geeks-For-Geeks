//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int>v;
        int sum = arr[0];
        int i = 0, j = 0;
        while(i < n and j < n){
            if(sum == s){
                v.emplace_back(i + 1);
                v.emplace_back(j + 1);
                return v;
            }
            else if(sum > s and i < j){
                sum -= arr[i];
                i++;
                continue;
            }
            else{
                j++;
                if(j < n) sum += arr[j];
            }
        }
        v.emplace_back(-1);
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends