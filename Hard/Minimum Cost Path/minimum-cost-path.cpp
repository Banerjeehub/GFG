//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<vector<int>>dp(rowSize+1, vector<int>(colSize, 1e9));
        
        int dRow[] = {0, 0, 1, -1};
        int dCol[] = {1, -1, 0, 0};
        
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        dp[0][0] = grid[0][0];
        pq.push({dp[0][0], {0, 0}});
        
        while(!pq.empty())
        {
            
            
            int cost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
        
            for(int i=0; i<4; i++)
            {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                
                if(newRow >=0 and newCol >=0 and newRow < rowSize and newCol < colSize)
                {
                    if(dp[newRow][newCol] > cost + grid[newRow][newCol])
                    {
                        dp[newRow][newCol] = cost + grid[newRow][newCol];
                        pq.push({dp[newRow][newCol], {newRow, newCol}});
                    }
                }
                
            }
            
            
        }
        
        return dp[rowSize-1][colSize-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends