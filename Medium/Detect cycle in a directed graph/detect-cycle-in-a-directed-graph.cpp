//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detect(int node, vector<int>&visited, vector<int>&pathVisited, vector<int>adj[])
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(detect(it, visited, pathVisited, adj)) return true;
            }
            else if(pathVisited[it]) return true;
        }
        
        pathVisited[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int>visited(V, 0);
        vector<int>pathVisited(V, 0);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(detect(i, visited, pathVisited, adj)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends