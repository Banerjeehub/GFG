//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define vin vector<int>
#define p push_back
class Solution {
    
  private:
    int time = 0;
    void dfs(int node, int parent, vin adj[], vin &visited, vin &tin, vin &low, vin &ap)
    {
        visited[node] = 1;
        tin[node] = low[node] = ++time;
        int child = 0;
        
        for(auto it : adj[node])
        {
            if(it == parent) continue;
            if(!visited[it])
            {
                dfs(it, node, adj, visited, tin, low, ap);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1)
                {
                    ap[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 and parent == -1)
        {
            ap[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vin visited(V,0), tin(V), low(V), ap(V, 0), ans;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(i, -1, adj, visited, tin, low, ap);
            }
        }
        
        for(int i=0; i<V; i++)
        {
            if(ap[i] == 1) ans.p(i);
        }
        if(ans.size() == 0) return {-1};
        return ans;
        
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends