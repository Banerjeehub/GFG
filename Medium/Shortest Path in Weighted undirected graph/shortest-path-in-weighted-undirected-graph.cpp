//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        //......make the adj-List......
        
        vector<pair<int, int>>adj[n+1];
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // .......init the priority_queue.........
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        
        //init the dist array and parent array and pre-init it with 0 in the frst spot
        
        vector<int>dist(n+1, 1e9), parent(n+1);
        dist[1] = 0;
        for(int i=1;i<=n;i++)
            parent[i] = i;
        //now the traversal throught the pq
        
        pq.push({0, 1});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int eW = it.second;
                int adjNode = it.first;
                if(dis + eW < dist[adjNode])
                {
                    dist[adjNode] = dis + eW;
                    pq.push({dis+eW, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
    
        vector<int>path;
        int ver = n;
        while(parent[ver] != ver)
        {
            path.push_back(ver);
            ver = parent[ver];
        }
        
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends