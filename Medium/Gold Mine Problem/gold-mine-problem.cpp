//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &M, vector<vector<int>> &dp){
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = solve(i-1, j+1, n, m, M, dp);
        int b = solve(i, j+1, n, m, M, dp);
        int c = solve(i+1, j+1, n, m, M, dp);
        
        return dp[i][j] = max(max(a, b), c)+M[i][j];
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0 ; i < n ; i++){
            int a = solve(i, 0, n, m, M, dp);
            if(a > ans) ans = a;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends