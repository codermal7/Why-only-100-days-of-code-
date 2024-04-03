//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int node,vector<int> adj[], int vis[])
    {
      vis[node]=1;
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
            dfs(it,adj,vis);
          }
      }
    }
    public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> ad[V];int c=0;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i,ad,vis);
            }
        }
        return c;    
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