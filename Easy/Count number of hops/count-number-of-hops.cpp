//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod = 1e9 + 7;
    long long code(int i , vector<long long> &dp)
    {
        if(i < 0) return 0;
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];
        return dp[i] = (code(i-1 , dp) + code(i-2 , dp) + code(i-3 , dp))%mod;
    }
    long long countWays(int n)
    {
        vector<long long> dp(n + 1 , -1);
        return code(n , dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends