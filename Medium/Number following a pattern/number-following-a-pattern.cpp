//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string s="1";
        char j='2';
        int r=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='I'){
                r=0;
                s.push_back(j);
                j++;
    
            }
            else{
                r++;
                string temp="";
                for(int k=0;k<r;k++){
                    temp.push_back(s[s.size()-1]);
                    s.pop_back();
                }
                s.push_back(j);
                j++;
                reverse(temp.begin(),temp.end());
                s=s+temp;
            }
        }
        return s;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends