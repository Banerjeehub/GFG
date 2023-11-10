//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  private:
    int getLCS(string a, string b)
    {
        int n = a.size();
        
        vector<int>prev(n+1, 0);
        vector<int>curr(n+1, 0);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1] == b[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            swap(prev, curr);
        }
        
        return prev[n];
    }
  public:
    int longestPalinSubseq(string A) 
    {
        string B = A;
        reverse(B.begin(), B.end());
        return getLCS(A, B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends