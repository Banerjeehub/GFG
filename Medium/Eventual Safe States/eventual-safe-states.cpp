//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool DFS(int node,int check[], int visited[], int pathVisited[], vector<int> adj[])
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(DFS(it,check, visited, pathVisited, adj))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVisited[it])
            {
                check[node] = 0;
                return true;
            }
        }
        
        pathVisited[node] = 0;
        check[node] = 1;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        int visited[V] = {0};
        int pathVisited[V] = {0};
        int check[V] = {0};
        
        for(int i=0; i<V; i++)
       {
           if(!visited[i])
           {
               DFS(i, check, visited, pathVisited, adj);
           }
       }
        
        for(int i=0; i<V; i++)
        {
            if(check[i] == 1) ans.push_back(i);
        }
        
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends