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
                dfs(isConnected,i);
                c++;
            }
        }
        return c;
    }
};

// class Solution {
//     int res,n,vis[201]={0};
//     void dfs(vector<vector<int>>& isConnected,int start)
//     {
//         vis[start] = 1;
//         for(int connection = 0;connection<n;connection++)
//         {
//             if(!vis[connection] and isConnected[start][connection]) 
//             dfs(isConnected,connection);
//         }
//     }

//     // void dfs
// public:
//     int findCircleNum(vector<vector<int>>& isConnected)
//      {
//         n = isConnected.size();
//         for(int i = 0;i<n;i++) 
//         if(!vis[i]) 
//         {
//             dfs(isConnected,i);
//             res++;
//         }
//         return res;   
//     }
// };