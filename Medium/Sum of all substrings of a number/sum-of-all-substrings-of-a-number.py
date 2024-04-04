#User function Template for python3

class Solution:
    #Function to find sum of all possible substrings of the given string.
    def sumSubstrings(self,number):
        # code here
        mod = 1000000007
        
        n = len(number)
        result = 0
        multiplier = 1
    
        for i in range(n - 1, -1, -1):
            digit = int(number[i])
            result += digit * (i + 1) % mod * multiplier % mod
            multiplier = multiplier * 10 % mod + 1 
    
        return result % mod


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

import sys
sys.setrecursionlimit(10**6)

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s = str(input())
        ob=Solution()
        print(ob.sumSubstrings(s))
# } Driver Code Ends