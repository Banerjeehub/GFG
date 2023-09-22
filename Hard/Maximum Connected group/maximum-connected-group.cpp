//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisJointSet
{
public:
    vector<int> parent, rank, size;

    DisJointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; 
            size[i] = 1;
        }    
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        else if (rank[pu] < rank[pv])
            parent[pv] = pu;

        else if (rank[pv] < rank[pu])
            parent[pu] = pv;

        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        else if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
  private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DisJointSet ds(n * n);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) continue;
                int dr[] = {0, 0, 1, -1};
                int dc[] = {1, -1, 0, 0};
                for(int k=0; k<4; k++)
                {
                    int nRow = i + dr[k];
                    int nCol = j + dc[k];
                    if(isValid(nRow, nCol, n) && grid[nRow][nCol] == 1)
                    {
                        int node = i * n + j;
                        int adjNode = nRow * n + nCol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int mxAns = INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) continue;
                int dr[] = {0, 0, 1, -1};
                int dc[] = {1, -1, 0, 0};
                set<int>parents;
                for(int k=0; k<4; k++)
                {
                    int nRow = i + dr[k];
                    int nCol = j + dc[k];
                    if(isValid(nRow, nCol, n))
                    {
                        if(grid[nRow][nCol] == 1)
                        {
                            parents.insert(ds.findUParent(nRow * n + nCol));
                        }
                        
                    }
                }
                
                int temp = 0;
                for(auto it : parents)
                {
                    temp += ds.size[it];
                }
                
                mxAns = max(temp+1, mxAns);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mxAns = max(mxAns, ds.size[ds.findUParent(cellNo)]);
        }
        return mxAns;
        
        
    }
};























//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends