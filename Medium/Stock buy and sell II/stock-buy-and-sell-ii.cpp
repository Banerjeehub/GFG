//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    int helper(int idx, int liberty, int n, vector<int>&prices, vector<vector<int>>&dp)
    {
        if(idx == n) return 0;
        if(dp[idx][liberty] != -1) return dp[idx][liberty];
        int profit = 0;
        
        if(liberty)
        {
            profit = max(-prices[idx]+helper(idx+1, 0, n, prices, dp),
                        helper(idx+1, 1, n, prices,dp));
        }
        else
        {
            profit = max(prices[idx]+helper(idx+1, 1, n, prices, dp),
                                    helper(idx+1, 0, n, prices, dp));
        }
        
        return dp[idx][liberty] =  profit;
    }
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        //return helper(0, 1, n, prices, dp);
        
        for(int idx = n-1; idx>=0; idx--)
        {
            for(int liberty=0; liberty<=1; liberty++)
            {
                int profit = 0;
                if(liberty)
                    {
                        profit = max(-prices[idx]+dp[idx+1][0] , dp[idx+1][1]);
                    }
                else
                    {
                    profit = max(prices[idx]+dp[idx+1][1],
                                    dp[idx+1][0]);
                    }
                    
                    dp[idx][liberty] = profit;
        
            }
        }
        
        return dp[0][1];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends