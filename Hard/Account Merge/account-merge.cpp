//{ Driver Code Starts
//Initial Template for C++
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
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int V = accounts.size();
        
        DisJointSet ds(V);
        unordered_map<string, int>mpp;
        //sort(accounts.begin(), accounts.end());
        for(int i=0; i<V; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end())
                {
                    mpp[mail] = i;
                }
                else
                {
                    ds.unionByRank(i, mpp[mail]);
                }
            }
        }
        
        vector<string>adj[V];
        for(auto it : mpp)
        {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            adj[node].push_back(mail);
        }
        
        
        vector<vector<string>>ans;
        
        for(int i=0; i<V; i++)
        {
            if(adj[i].size() == 0) continue;
            sort(adj[i].begin(), adj[i].end());
            
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : adj[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends