class Solution {
    private:
    // void dfs(int node,vector<int> adj[], int vis[])
    // {
    //   vis[node]=1;
    //   for(auto it:adj[node])
    //   {
    //       if(!vis[it])
    //       {
    //         dfs(it,adj,vis);
    //       }
    //   }
    // }
    void dfs(int V,int node,vector<vector<int>>& adj, int vis[])
    {
        int m=V;
      vis[node]=1;
        for(int i=0;i<m;i++)
          if(adj[node][i]==1 && !vis[i])
          {
            dfs(m,i,adj,vis);
          }
      }
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> ad[V+1];int c=0;
        // for(int i=1;i<V;i++)
        // {
        //     for(int j=1;j<V;j++)
        //     {
        //         if(isConnected[i][j]==1 && i!=j)
        //         {
        //             ad[i].push_back(j);
        //             // ad[j].push_back(i);
        //         }
        //     }
        // }
        int vis[V];
        memset(vis,0,V*sizeof(int));
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(V,i,isConnected,vis);
            }
        }
        return c;    
    }
};