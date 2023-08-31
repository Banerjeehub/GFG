//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source==destination) return 0;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        vector<vector<int>>dist(rowSize, vector<int>(colSize, 1e9));
        dist[source.first][source.second] = 0;
        
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {source.first, source.second}});
        
        vector<int>delRow, delCol;
        delRow = {0, 0, +1, -1};
        delCol = {+1, -1, 0, 0};
        
        
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(newRow >= 0 and newRow < rowSize
                and newCol >= 0 and newCol < colSize
                and grid[newRow][newCol] == 1
                and 1 + dis < dist[newRow][newCol])
                {
                    dist[newRow][newCol] = 1 + dis;
                    if(newRow == destination.first && newCol == destination.second) 
                        return dis + 1;
           
                    q.push({1+dis, {newRow, newCol}});
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends