class Solution {
public:
    int n,c,vis[201]={0};
    void dfs(vector<vector<int>>& isConnected, int node){
        vis[node]=1;
        for(int conn=0;conn<n;conn++)
        {
            if(!vis[conn] and isConnected[node][conn])
            dfs(isConnected, conn);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(isConnected,i);
            }
        }
        return c;
    }
};