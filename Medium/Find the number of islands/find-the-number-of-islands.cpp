//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  private:
    void BFS(int row, int col,vector<vector<int>>&visited, vector<vector<char>>&grid )
    {
        visited[row][col] = 1;
        queue<pair<int, int>>q;
        q.push({row, col});
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<= 1; j++)
                {
                    int newr = r + i;
                    int newc = c + j;
                    if(newr >= 0 && newr < rowSize && newc >= 0 && newc < colSize &&
                    !visited[newr][newc] && grid[newr][newc] == '1')
                    {
                        visited[newr][newc] = 1;
                        q.push({newr,newc});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
         int colSize= grid[0].size();
         
         //init the visited vector
         vector<vector<int>>visited(rowSize, vector<int>(colSize, 0));
         
         int count = 0;
         for(int row = 0; row < rowSize; row++)
         {
             for(int col = 0; col < colSize; col++)
             {
                 if(!visited[row][col] && grid[row][col] == '1')
                 {
                     count++;
                     BFS(row, col, visited, grid);
                 }
             }
         }
         
         return count;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends