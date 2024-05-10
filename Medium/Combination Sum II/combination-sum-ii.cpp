//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void FindCombinations(int ind, vector<int> &candidates, vector<vector<int>> &ans, vector<int> ds, int target){
        if(target == 0){
            ans.emplace_back(ds);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.emplace_back(candidates[i]);
            FindCombinations(i+1,candidates,ans,ds,target - candidates[i]);
            ds.pop_back();
        }
    }

    vector<vector<int>> CombinationSum2(vector<int>& arr, int n, int k) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        vector<int> ds;
        FindCombinations(0,arr,ans,ds,k);
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends