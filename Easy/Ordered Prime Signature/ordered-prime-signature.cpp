//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void count(int *prime ,int n, unordered_map<int,int>&mp){
        while(n!=1){
            mp[prime[n]]++;
            n = n / prime[n];
        }
    }

    vector<int> orderedPrime(int n){
        // code here
        int prime[n+1],all=1;
        for(int i = 2 ; i <= n ; i++){
        	prime[i]=i;
        	if(n%i==0)all++;
        }
        prime[0]=0;
        prime[1]=1;
        for(int i = 2 ; i * i <= n ; i++){
            if(prime[i]==i){
                for(int p = i * i ; p <= n ; p += i){
                    prime[p]=i;
                }
            }
        }
        unordered_map<int,int>mp;
        count(prime,n,mp);
        vector<int>v;
        for(auto it:mp){
            v.emplace_back(it.second);
        }
        v.emplace_back(all);
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.orderedPrime(n);
        for(int i = 0;i < ans.size()-1;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        cout<<ans[ans.size()-1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends