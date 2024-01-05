//https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1


class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    long long md = 1000000007;
	    long long f = 2,s = 3,t,c=2;
	    if(N==0)return 1;
	    if(N==1)return (f*f)%md;
	    else if(N==2)return (s*s)%md;
	    else{
	        while(c<N){
	            t = f+s;
	            f=s;
	            s=t;
	            c++;
	            f%=md;
	            s%=md;
	            t%=md;
	        }
	        return (t*t)%md;
	    }
	}
};
