//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisJointSet
{
public:
    vector<int>parent, rank;

    DisJointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findUParent(int node)
    {
        if(node == parent[node]) return node;
        else return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) return;

        else if(rank[pu] < rank[pv]) parent[pv] = pu;

        else if(rank[pv] < rank[pu]) parent[pu] = pv;

        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        
        DisJointSet ds(n);
        int extraCount = 0;
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            
            if(ds.findUParent(u) == ds.findUParent(v)) extraCount++;
            else
            {
                ds.unionByRank(u, v);
            }
        }
        
        
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i] == i) count++;
        }
        int ans = count - 1;
        
        if(extraCount >= ans) return ans;
        else return -1;
    }
};





























//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends 