//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    private:
    int lcs(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        
        vector<int>prev(m+1, 0);
        vector<int>curr(m+1, 0);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(curr[j-1], prev[j]);
            }
            swap(prev, curr);
        }
        
        return prev[m];
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int M, int N)
    {
        //code here
        return M + N - lcs(X, Y);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends