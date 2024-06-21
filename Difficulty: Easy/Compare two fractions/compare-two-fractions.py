#User function Template for python3


class Solution:
    def compareFrac (self, str):
        # code here
        
        s = str.split(",")
        a = eval(s[0])
        b = eval(s[1])
        
        if a == b:
            return 'equal'
        elif a < b:
            return s[1].replace(" ", "")
        else:
            return s[0].replace(" ", "")



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import re

if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        str = input()
        print(ob.compareFrac(str))

# } Driver Code Ends