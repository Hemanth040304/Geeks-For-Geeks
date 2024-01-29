//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

    void fun(vector<string> &ans, vector<vector<char>> &board, string &ch, vector<vector<int>>&vis, string s, int i, int j, int k){
        // cout<<ch<<" "<<s<<endl;
        if(ch==s){
            ans.emplace_back(s);
            // cout<<i<<" "<<j<<"\n";/
            return;
        }
        for(int a = -1 ; a < 2 ; a++){
            int g = ans.size();
            for(int b = -1 ; b < 2 ; b++){
                int nrow=i+a;
                int ncol=j+b;
                
                if(k<=ch.size() and nrow>=0 and nrow<board.size() and ncol>=0 and ncol<board[0].size() and !vis[nrow][ncol] and board[nrow][ncol]==ch[k]){
                    vis[nrow][ncol]=1;
                    s+=ch[k];
                    g = ans.size();
                    fun(ans,board,ch,vis,s,nrow,ncol,k+1);
                    s.pop_back();
                    vis[nrow][ncol]=0;
                    if(g!=ans.size())break;
                }
            }
            if(g!=ans.size())break;
        }
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dic) {
	    // Code here
	    vector<string>ans;
	    int k=0,g=0;
	    vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
	    for(int h = 0 ; h < dic.size() ; h++){
    	    for(int a = 0 ; a < board.size() ; a++){
                for(int b = 0 ; b < board[0].size() ; b++){
                        if(board[a][b]==dic[h][0]){
                            fun(ans,board,dic[h],vis,"",a,b,0);
                            if(g!=ans.size())break;
                            //if(ans.back()==dic[h])break;
                        }
                }
                if(g!=ans.size()){
                    g = ans.size();
                    break;
                }
                // if(ans.back()==dic[h])break;/'/'
            }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends