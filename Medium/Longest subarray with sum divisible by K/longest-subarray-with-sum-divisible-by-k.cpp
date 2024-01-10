//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++



class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    map<int,int>mp;
	    int s=0,j=0;
	    mp[0]=-1;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        s+=arr[i];
	        int rem=s%k;
	        if(rem<0){
	            rem+=k;
	        }
	        if(mp.find(rem)==mp.end()) mp[rem]=i;
	        else ans=max(ans,i-mp[rem]);
	    }
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends