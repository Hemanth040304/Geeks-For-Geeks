//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) { 
        // Your code here
        vector<int> topToLow;
        vector<int> lowToTop(n,0);
        
        topToLow.emplace_back(a[0]);
        
        for (int i = 1; i < n; i++) {
            if(topToLow.back() > a[i]) topToLow.emplace_back(a[i]);
            else topToLow.emplace_back(topToLow.back());
        }
        
        lowToTop[n - 1] = a[n - 1];
        for (int i = n - 2; i > -1; i--){
            if(lowToTop[i + 1] < a[i]) lowToTop[i] = a[i];
            else lowToTop[i] = lowToTop[i + 1];
        }
        
        int leftMost = 0, rightMost = 0;
        int ans = 0;
        
        while(leftMost < n and rightMost < n){
            while(topToLow[leftMost] <= lowToTop[rightMost] and rightMost < n) {
                rightMost++;
                ans = max( ans, rightMost - leftMost - 1);
            }
            leftMost++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends