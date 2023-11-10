//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getLCS(string s, string t)
    {
        int n = s.size();

        vector<int>prev(n+1, 0);
        vector<int>curr(n+1, 0);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == t[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }

            swap(curr, prev);
        }

        return prev[n];
    }

    int longestPalindromicSubsequence(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return getLCS(s, t);
    }
    int findMinInsertions(string S){
        return S.size() - longestPalindromicSubsequence(S);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends