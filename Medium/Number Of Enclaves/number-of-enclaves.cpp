//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        vector<int>delRow, delCol;
        vector<vector<int>>visited(rowSize, vector<int>(colSize, 0));
        queue<pair<int, int>>q;
        
        delRow = {0, 0, 1, -1};
        delCol = {1, -1, 0, 0};
        
        for(int i=0; i<colSize; i++)
        {
            if(grid[0][i] == 1)
            {
                visited[0][i] = 1;
                q.push({0, i});
            }
            if(grid[rowSize-1][i] == 1)
            {
                visited[rowSize-1][i] = 1;
                q.push({rowSize-1, i});
            }
        }
        for(int i=0; i<rowSize; i++)
        {
            if(grid[i][0] == 1)
            {
                visited[i][0] = 1;
                q.push({i, 0});
            }
            if(grid[i][colSize-1] == 1)
            {
                visited[i][colSize-1] = 1;
                q.push({i, colSize-1});
            }
        }
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(newRow >= 0 and newRow < rowSize
                and newCol >= 0 and newCol < colSize
                and !visited[newRow][newCol] 
                and grid[newRow][newCol] == 1)
                {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(!visited[i][j] and grid[i][j] == 1) ans++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends