//{ Driver Code Starts
//Initial Template for C#


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DriverCode
{

    class GFG
    {
        static void Main(string[] args)
        {
            int testcases;// Taking testcase as input
            testcases = Convert.ToInt32(Console.ReadLine());
            while (testcases-- > 0)// Looping through all testcases
            {
                var ip = Console.ReadLine().Trim().Split(' ');
                int n = int.Parse(ip[0]);
                int x = int.Parse(ip[1]);
                int[] arr = new int[n];
                ip = Console.ReadLine().Trim().Split(' ');
                for (int i = 0; i < n; i++)
                {
                    arr[i] = int.Parse(ip[i]);
                }
                Solution obj = new Solution();
                var res = obj.find(arr, n, x);
                Console.WriteLine(res[0] + " " + res[1] + " ");
            }

        }
    }
}

// } Driver Code Ends


//User function Template for C#

class Solution
    {
        //Complete this function
        //Function to count number of pairs such that x^y is greater than y^x
        public List<int> find(int[] arr, int n, int x)
        {
            //Your code here
            List<int> result = new List<int>();
            int first = -1, last = -1;
            for (int i = 0; i < n; i++){
                if (x != arr[i])continue;
                if (first == -1)first = i;
                last = i;
            }
            result.Add(first);
            result.Add(last);
            return result;
        }
    }