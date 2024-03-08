//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s){
	    // code here
	    vector<int> diff;
	    map<char, int> mp;
	    int mini = INT_MAX, maxi = INT_MIN;
	    for (auto it : s) mp[it]++;
	    for (auto it : mp) {
	       // int count = it.second; 2 2 3 3 
	       // if (mini > count) mini = count;
	       // if (maxi < count) maxi = count;
	       diff.emplace_back(it.second);
	    }
	    sort(diff.begin(), diff.end());
	    int count = 0;
	    for (int i = 0; i < diff.size() - 1; i++){
	        if(diff[i] < diff[i+1] and diff[i] != 1){
	            if(abs(diff[i] - diff[i+1]) == 1){
	                if(count == 0) {
	                    diff[i+1] -= 1;
	                    count++;
	                }
	                else return 0;
	            }
	            else{
	                if(diff[i] == 1 and count == 0){
	                    count++;
	                }
	                else return 0;
	            }
	        }
	        else if(diff[i] == 1) count++;
	    }
	    return 1;
	   // if (maxi <= mini + 1) return 1;
	   // return 0;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends