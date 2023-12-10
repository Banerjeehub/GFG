//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, int *pathVisited, int *visited, vector<int> adj[])
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it, pathVisited, visited, adj)) return true;
            }
            if(pathVisited[it]) return true;
            
        }
        pathVisited[node] = 0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
       int visited[v] = {0};
       int pathVisited[v] = {0};
       for(int i=0; i<v; i++)
       {
           if(!visited[i])
           {
               if(dfs(i, pathVisited, visited, adj)) return true;
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