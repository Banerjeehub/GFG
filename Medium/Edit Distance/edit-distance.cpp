//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int memoi(string &s, string &t, int i, int j, vector<vector<int>>&dp)
    {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = memoi(s, t, i-1, j-1, dp);
        return dp[i][j] = 1 + min(memoi(s, t, i-1, j-1, dp), min(memoi(s, t, i-1, j, dp), memoi(s, t, i, j-1, dp)));
    }
    int tabulation(string s, string t, int n, int m, vector<vector<int>>&dp)
    {
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int i=0; i<=m; i++) dp[0][i] = i;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
    int spaceOptimisation(string &s, string &t, int n, int m)
    {
        vector<int>prev(m+1, 0);
        vector<int>curr(m+1, 0);
        
        for(int j=0; j<=m; j++) prev[j] = j;
        
        for(int i=1; i<=n; i++)
        {
            curr[0] = i;
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min(prev[j-1], min(prev[j], curr[j-1]));
            }
            swap(curr, prev);
        }
        
        return prev[m];
    }
  public:
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        //return memeoi(s, t, n-1, m-1, dp);
        //return tabulation(s, t, n, m, dp);
        return spaceOptimisation(s, t, n, m);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends