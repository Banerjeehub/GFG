//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    
    bool dfs(int start, vector<int>adj[], vector<bool>&visited, vector<bool>&recurStack)
    {
        visited[start] = true;
        recurStack[start] = true;
        
        // ppp
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                if(dfs(it,adj,visited,recurStack))
                {
                    return true;
                }
            }
            else if(recurStack[it])
            {
                return true;
            }
        }
        
        
        
            recurStack[start] = false;
            return false;
        
        

        
    }
    
    
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>recurStack(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,recurStack))
                {
                    return true;
                }
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