//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char>st;
        for(int i = 0 ; i < S.size() ; i++){
            if((st.empty()) and S[i]!='0' and K>0){
                st.push(S[i]);
            }
            else if(K>0){
                while(!(st.empty()) and st.top()>S[i]){
                    K--;
                    st.pop();
                    if(K==0){
                        break;
                    }
                }
                if(S[i]!='0'){
                    st.push(S[i]);
                }
                if(!(st.empty()) and S[i]=='0')st.push(S[i]);
            }
            else if(K==0 and i < S.size()){
                if(S[i]!='0'){
                    st.push(S[i]);
                }
                if(!(st.empty()) and S[i]=='0')st.push(S[i]);
            }
        }
        while(K-- and !(st.empty())){
            st.pop();
        }
        if(st.empty())return "0";
        string str = "";
        while(!(st.empty())){
            str+=st.top();
            st.pop();
        }
        for(int i = 0 , j = str.size()-1 ; i < j ; i++,j--){
            swap(str[i],str[j]);
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
