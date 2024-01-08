//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        
        void getLPS(string &txt, vector<int>&lps)
        {
            int size = txt.length();
            int i(0), j(1);
            lps[0] = 0;
            
            while(j < size)
            {
                if(txt[i] == txt[j])
                {
                    lps[j] = i+1;
                    i++;j++;
                }
                else
                {
                    if(i) i = lps[i-1];
                    else lps[j++] = 0;
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            vector<int>ans;
            int m = pat.length();
            int n = txt.length();
            
            vector<int>lps(m);
            getLPS(pat, lps);
            int i = 0;
            int j = 0;
            
            while(i < n)
            {
                if(pat[j] == txt[i])
                {
                    i++;j++;
                    if(j == m)
                    {
                        int val = i-j+1;
                        ans.push_back(val);
                        j = lps[j-1];
                    }
                }
                else if(j) j = lps[j-1];
                else i++;
            }
            
            if(ans.empty())return {-1};
            return ans;
            
            
        }   
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends