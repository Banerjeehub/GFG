//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool f(string &s, string &t, int i, int j, vector<vector<int>>&dp)
    {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(i >= 0 && j < 0)
        {
            for(int p=0; p<=i; p++)
            {
                if(s[p] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j] || s[i] == '?') return dp[i][j] = f(s, t, i-1, j-1, dp);
        else if(s[i] == '*') return dp[i][j] = f(s, t, i-1, j, dp) || f(s, t, i, j-1, dp);
        return dp[i][j] = false;
    }
    
    int wildCard(string pattern,string str)
    {
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return f(pattern, str, n , m, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends