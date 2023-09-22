//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisJointSet
{
public:
    std ::vector<int> parent, rank, size;

    DisJointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
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
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        else if (size[pv] < size[pu])
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
    bool isValid(int newRow, int newCol, int rowSize, int colSize)
    {
        return newRow < rowSize && newCol < colSize && newRow >= 0 && newCol >= 0;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisJointSet ds(n * m);
        vector<int>ans;
        int cnt = 0;
        int visited[n][m];
        memset(visited, 0, sizeof visited);
        
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            
            if(visited[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            visited[row][col] = 1;
            cnt++;
            
            int delRow[] = {0, 0, 1, -1};
            int delCol[] = {1, -1, 0, 0};
            
            for(int i=0; i<4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(isValid(nRow, nCol, n, m))
                {
                    if(visited[nRow][nCol] == 1)
                    {
                        int nodeNum = row * m + col;
                        int adjNode = nRow * m + nCol;
                        
                        if(ds.findUParent(nodeNum) != ds.findUParent(adjNode))
                        {
                            cnt--;
                            ds.unionBySize(nodeNum, adjNode);
                        }
                    }
                }
                
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends