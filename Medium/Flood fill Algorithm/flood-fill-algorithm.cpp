//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void DFS(int row, int col, vector<int>delRow, vector<int>delCol, vector<vector<int>>& image, 
                vector<vector<int>>& ans, int newColor, int iniColor)
    {
        ans[row][col] = newColor;
        int rowSize = image.size();
        int colSize = image[0].size();
        
        for(int i=0; i<4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if(newRow >= 0 && newRow < rowSize &&
               newCol >= 0 && newCol < colSize &&
               image[newRow][newCol] == iniColor && ans[newRow][newCol] != newColor)
               {
                   DFS(newRow, newCol, delRow, delCol, image, ans, newColor, iniColor);
               }
        }
    }
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         vector<vector<int>>ans = image;
         int iniColor = image[sr][sc];
         vector<int>delRow = {-1, +1, 0, 0};
         vector<int>delCol = {0, 0, +1, -1};
         
         DFS(sr, sc, delRow, delCol, image, ans,  newColor, iniColor);
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends