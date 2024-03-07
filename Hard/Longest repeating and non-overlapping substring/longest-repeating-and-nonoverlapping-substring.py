#User function Template for python3

class Solution:
    def longestSubstring(self, s , n):
        # code here 
        # ans = "-1"
        
        # for _ in range(0,n):
        #     for i in range(_+1,n):
        #         t = s[_:i]
        #         # print(t, s[i+1:n])
        #         if t in s[i+1:]:
        #             if ans == "-1" or len(ans) < len(t):
        #                 ans = t
        
        # return ans
        i, j = 0, 0
        ans = ""
        
        while i < n and j < n:
            t = s[i:j + 1]
            if t in s[j + 1:n]:
                if ans == "" or len(ans) < len(t):
                    ans = t
            else:
                i += 1
            j += 1
        
        if ans == "":
            return "-1"
        
        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        S=input()
        
        ob = Solution()
        print(ob.longestSubstring(S , N))
# } Driver Code Ends