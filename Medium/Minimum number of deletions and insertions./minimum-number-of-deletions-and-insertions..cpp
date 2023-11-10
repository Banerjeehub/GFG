//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	int lcs(string s1, string s2)
	{
	    int n = s1.size();
	    int m = s2.size();
	    
	    vector<int>prev(m+1, 0);
	    vector<int>curr(m+1, 0);
	    
	    for(int i=1; i<=n; i++)
	    {
	        for(int j=1; j<=m; j++)
	        {
	            if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
	            else curr[j] = max(curr[j-1], prev[j]);
	        }
	        
	        swap(prev, curr);
	    }
	    
	    return prev[m];
	}

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.size();
	    int m = str2.size();
	    
	    return n+m - 2*lcs(str1, str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends