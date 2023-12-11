//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
         
        long maxVal = INT_MIN;
        long sum = 0;
        for(int i=0; i<K; i++)
        {
            sum += arr[i];
        }
        maxVal = sum;
        int start = 0;
        for(int i=K; i<N; i++)
        {
            sum += arr[i] - arr[start++];
            maxVal = max(maxVal, sum);
        }
        
        return maxVal;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends