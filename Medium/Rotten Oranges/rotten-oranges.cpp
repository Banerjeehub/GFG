//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        int visited[rowSize][colSize];
        int freshCount = 0;
        queue<pair<pair<int, int>, int>> q;
        
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }
                
                if (grid[i][j] == 1) freshCount++;
            }
        }
        int count = 0;
        int res = 0;
        int delRow[] = {0, 0, -1, +1};
        int delCol[] = {+1, -1, 0, 0};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop(); 
            res = max(res, t);
            for (int i = 0; i < 4; i++) {
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];
                
                if (newRow >= 0 && newRow < rowSize
                    && newCol >= 0 && newCol < colSize
                    && visited[newRow][newCol] != 2
                    && grid[newRow][newCol] == 1) {
                    
                    q.push({{newRow, newCol}, t + 1});
                    visited[newRow][newCol] = 2;
                    count++;
                }
            }
        }
        
        if (count != freshCount) return -1;
        return res;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends