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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> ad[V];int c=0;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        int vis[V];
        memset(vis,0,V*sizeof(int));
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