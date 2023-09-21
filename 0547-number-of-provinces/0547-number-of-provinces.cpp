// class Solution {
//     private:
//     void dfs(int node,vector<int> adj[], int vis[])
//     {
//       vis[node]=1;
//       for(auto it:adj[node])
//       {
//           if(!vis[it])
//           {
//             dfs(it,adj,vis);
//           }
//       }
//     }
//     public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V=isConnected.size();
//         vector<int> ad[V];int c=0;
//         for(int i=0;i<V;i++)
//         {
//             for(int j=0;j<V;j++)
//             {
//                 if(isConnected[i][j]==1 && i!=j)
//                 {
//                     ad[i].push_back(j);
//                     // ad[j].push_back(i);
//                 }
//             }
//         }
//         int vis[V];
//         memset(vis,0,V*sizeof(int));
//         for(int i=0;i<V;i++)
//         {
//             if(!vis[i])
//             {
//                 c++;
//                 dfs(i,ad,vis);
//             }
//         }
//         return c;    
//     }
// };

// class Solution {
// private:
//     void dfs()
//     {

//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V=isConnected.size();
//         vector<int> al[V];int c=0;
//         int vis[v]={0};
//         for(int i=0;i<V;i++)
//         {
//             for(int j=0;j<V;j++){
//                 if(isConnected[i][j] && i!=j) 
//                 {
//                     al[i].push_back(j);
//                 }
//             }   
//         }
//     }
// };

class Solution {
    int res,c = 0,n,vis[201]={0};
    void dfs(vector<vector<int>>& isConnected,int start)
    {
        vis[start] = true;c++;
        for(int connection = 0;connection<n;connection++)
        {
            if(!vis[connection] and isConnected[start][connection]) dfs(isConnected,connection);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected)
     {
        n = isConnected.size();
        for(int i = 0;i<n;i++) if(!vis[i]) c=0,dfs(isConnected,i),res++;;
        return res;   
    }
};