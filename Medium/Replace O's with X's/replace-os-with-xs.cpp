//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void replaceByDFS(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &visited,
                      vector<int>delRow, vector<int>delCol)
    {
        visited[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if(newRow >= 0 && newRow < n 
            && newCol >= 0 && newCol < m
            && !visited[newRow][newCol] 
            &&
            mat[newRow][newCol] == 'O')
            {
                replaceByDFS(newRow, newCol, mat, visited, delRow, delCol);
            }
        }
        
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<int>delRow, delCol;
        delRow = {0, 0, 1, -1};
        delCol = {1, -1, 0, 0};
        
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i=0; i<m; i++)
        {
            if(!visited[0][i] && mat[0][i] == 'O')
            {
                replaceByDFS(0, i, mat, visited, delRow, delCol);
            }
            if(!visited[n-1][i] && mat[n-1][i] == 'O')
            {
                replaceByDFS(n-1, i, mat, visited, delRow, delCol);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i][0] && mat[i][0] == 'O')
            {
                replaceByDFS(i, 0, mat, visited, delRow, delCol);
            }
            if(!visited[i][m-1] && mat[i][m-1] == 'O')
            {
                replaceByDFS(i, m-1, mat, visited, delRow, delCol);
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0 ;j<m;j++) {
                if(!visited[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends