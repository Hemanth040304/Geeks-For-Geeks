//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    void makePrime(int *prime,int R){
	        for(int i = 2 ; i <= R ; i++){
	            prime[i]=1;
	        }
	        prime[0]=0;
	        prime[1]=0;
	        for(int i = 2 ; i*i <= R ; i++){
	            if(prime[i]==1){
	                for(int j = i*i ; j <= R ; j+=i){
	                    prime[j]=0;;
	                }
	            }
	        }
	    }
	
		int Count(int L, int R){
		    // Code here
		    int prime[R+1];
		    makePrime(prime,R);
		    /*for(int i = 0 ; i < R ; i++){
		        cout<<i<<" "<<prime[i]<<"\n";
		    }*/
		    int comp=0,pri=0;
		    for(int i = L ; i <= R ; i++){
		        if(prime[i]==0 and i!=1){
		            comp++;
		            //cout<<i<<"C ";
		        }
		        else if(prime[i]==1 and i!=1){
		            pri++;
		            //cout<<i<<"P ";
		        }
		    }
		    return comp-pri;
		}

};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends