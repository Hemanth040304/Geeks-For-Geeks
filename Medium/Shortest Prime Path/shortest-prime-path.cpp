//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

vector<int>prime(10000,1);
void seive(){
        prime[0]=0;
        prime[1]=0;
        for (int p = 2; p * p < 10000 ; p++) {
            if (prime[p] == 1) {
                for (int i = p * p; i < 10000 ; i += p)
                    prime[i] = 0;
            }
        }
    }

class Solution{   
public:

    int solve(int num1,int num2)
    {   
        //code her
        seive();
        queue<pair<string,int>>q;
        string s1=to_string(num1);
        string s2=to_string(num2);
        vector<int>vis(10000,0);
        q.push({s1,0});
        while(!q.empty()){
            string str=q.front().first;
            int c=q.front().second;
            q.pop();
            if(str==s2){
                return c;
            }
            c+=1;
            for(int i=0;i<str.size();i++){
                char ch = str[i];
                for(int j=0;j<=9;j++){
                    str[i]=j+'0';
                    if(i==0 and j==0)continue;
                    int n=stoi(str);
                    if(prime[n] and !vis[n]){
                        vis[n]=1;
                        q.push({str,c});
                    }
                }
                str[i] = ch;
            }
        }
        return -1;
    
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends