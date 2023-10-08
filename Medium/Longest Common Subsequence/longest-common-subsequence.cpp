//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence
using v2in = vector<vector<int>>;
using vin = vector<int>;

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int helper(int index2, int index1, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(index1 < 0 || index2 < 0) return 0;
        
        if(dp[index2][index1] != -1) return dp[index2][index1];
        
        if(s1[index2] == s2[index1]) return dp[index2][index1] =  1 + helper(index2-1,index1-1, s1,s2, dp);
        
        return dp[index2][index1] =  max(helper(index2-1, index1, s1,s2,dp), helper(index2, index1-1, s1, s2, dp));
    }
    int lcs(int n, int m, string s1, string s2)
    {
        int index2 = n-1;
        int index1 = m-1;
        
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return helper(index2, index1, s1, s2,dp);
    }   
};



//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends