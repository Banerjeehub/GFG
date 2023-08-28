//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int rowSize = grid.size();
	    int colSize = grid[0].size();
	    
	    queue<pair<pair<int, int>, int>>q;
	    vector<vector<int>>visited(rowSize, vector<int>(colSize, 0));
	    vector<vector<int>>result(rowSize, vector<int>(colSize, 0));
	    
	    vector<int>delRow, delCol;
	    delRow = {0, 0, -1, 1};
	    delCol = {1, -1, 0, 0};
	    
	    for(int i=0; i<rowSize; i++)
	    {
	        for(int j=0; j<colSize; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                visited[i][j] = 1;
	                q.push({{i, j}, 0});
	                
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        result[row][col] = steps;
	        
	        for(int i=0 ;i<4; i++)
	        {
	            int newRow = row + delRow[i];
	            int newCol = col + delCol[i];
	            
	            if(newRow >= 0 && newRow < rowSize
	            && newCol >= 0 && newCol < colSize
	            && !visited[newRow][newCol])
	            {
	                visited[newRow][newCol] = 1;
	                q.push({{newRow, newCol}, steps+1});
	            }
	        }
	    }
	    
	    return result;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends