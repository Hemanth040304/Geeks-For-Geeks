//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int f=-1,l=-1;
        vector<int>v={-1,-1};
        for(int i = 0 ; i < n ; i++){
            if(arr[i]==x){
                v[0]=i;
                //f=i;
                break;
            }
        }
        for(int i = n-1 ; i > -1 ; i--){
            if(arr[i]==x){
                v[1]=i;
                //l=i;
                break;
            }
        }
        return v;
        //return {f,l};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends