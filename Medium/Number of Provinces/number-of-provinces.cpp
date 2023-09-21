//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
    int numProvinces(vector<vector<int>> adj, int V) {
        
        DisJointSet ds(V);
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(adj[i][j] == 1)
                {
                    ds.unionByRank(i, j);
                }
            }
        }
        
        
        int cnt = 0;
        for(int i=0; i<V; i++)
        {
            if(ds.parent[i] == i) cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends