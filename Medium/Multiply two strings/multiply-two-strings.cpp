//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        
        if(s1 == "0" || s2 == "0") return "0";
        
        int flag = 0;
        if(s1[0] == '-' && s2[0] == '-') flag = 1;
        else if(s1[0] == '-' || s2[0] == '-') flag = 2;
        
        
        
        vector<int>ans(s1.length()+s2.length(), 0);;
        
        for(int i=s1.length()-1; i>=0; i--)
        {
            if(s1[i] == '-') continue;
            for(int j=s2.length()-1; j>=0; j--)
            {
                if(s2[j] == '-') continue;
                ans[i+j+1] += (s1[i]-'0') * (s2[j] - '0');
                ans[i+j] += ans[i+j+1] / 10;
                ans[i+j+1] %= 10;
            }
        }
        
        int i = 0;
        while(i < ans.size() && ans[i]==0)i++;
        string res="";
        if(flag == 2) res = "-";
        
        while(i < ans.size()) res.push_back(ans[i++] + '0');
        
        return res;
        
    }

};



//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends