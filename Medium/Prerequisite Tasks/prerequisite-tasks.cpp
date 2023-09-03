//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool DFS(int node, int visited[], int pathVisited[], vector<int>adj[])
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(DFS(it, visited, pathVisited, adj)) return true;
                
            }
            else if(pathVisited[it]) return true;
        }
        
        pathVisited[node] = 0;
        return false;
    }
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[V];
	    int visited[V] = {0};
	    int pathVisited[V] = {0};
	    
	    for(auto i : prerequisites)
	    {
	        adj[i.first].push_back(i.second);
	    }
	    
	    
	    for(int i=0; i<V; i++)
	    {
	        if(!visited[i])
	        {
	            if(DFS(i, visited, pathVisited, adj)) return false;
	        }
	    }
	    
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends