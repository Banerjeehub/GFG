//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int x, int y) {
        // code here
        if(A[0][0] == 0) return -1;
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>>pq;
        pq.push({{0,0}, 0});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int x = it.first.first;
            int y = it.first.second;
            int val = it.second;
            
            for(int i=0; i<4; i++)
            {
                int nr = dr[i] + x;
                int nc = dc[i] + y;
                
                if(nr >=0 && nr < n && nc >= 0 && nc < m && A[nr][nc] == 1)
                {
                    if(dist[nr][nc] > val + 1)
                    {
                        dist[nr][nc] = val+1;
                        pq.push({{nr,nc}, dist[nr][nc]});
                    }
                    
                }
            }
        }
        
        if(dist[x][y] == INT_MAX) return -1;
        return dist[x][y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends