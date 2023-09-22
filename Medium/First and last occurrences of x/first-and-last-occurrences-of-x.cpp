//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
vector<int> find(int arr[], int n , int x )
{
    vector<int>ans;
    sort(arr, arr+n);

    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            ans.push_back(i);
        }
        
    }
    
     vector<int>anss;
     if(ans.empty())
     {
         anss.push_back(-1);
         anss.push_back(-1);
         return anss;
     }
    
    int s = ans[0];
    int e = ans[ans.size()-1];
    
   
    anss.push_back(s);
    anss.push_back(e);

    
    return anss;
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends