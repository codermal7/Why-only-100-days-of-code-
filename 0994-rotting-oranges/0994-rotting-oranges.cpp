// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int cntfresh=0;
//         queue<pair< pair<int,int>, int>> q;
//         int vis[n][m];
//         // vector<vector<int>> vis(n, vector<int>(m, 0));
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]==2)
//                 {
//                     q.push({{i,j},0});
//                     vis[i][j]=2;
//                 }
//                 else if(grid[i][j]==1)
//                 cntfresh++;
//                 else
//                 vis[i][j]=0;
//             }
//         }
//         int tm=0,cnt=0;
//         int drow[4]={-1,0,1,0};
//         int dcol[4]={0,1,0,-1};

//         while(!q.empty())
//         {
//             int r=q.front().first.first;
//             int c=q.front().first.second;
//             int t=q.front().second;
//             tm=max(tm,t);
//             q.pop();
//             for(int i=0;i<4;i++)
//             {
//                 int nrow=r+drow[i];
//                 int ncol=c+dcol[i];
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
//                 && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
//                 {
//                     q.push({{nrow,ncol},t+1});
//                     vis[nrow][ncol]=2;
//                     cnt++;
//                 }
//             }
//         }

//         if(cnt!=cntfresh)
//         return -1;

//         return tm;
//     }
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        queue <pair < pair <int,int>,int > > q;
        int vis[n][m];
        int cnt=0,cnt_fr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)
                {
                    cnt_fr++;
                }
            }
        }
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int tm=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(auto d : dir) 
            {
                int drow = r + d.first;
                int dcol = c + d.second;
                if(drow>=0 && drow<n && dcol>=0 && dcol<m 
                && grid[drow][dcol]==1 && vis[drow][dcol]==0)
                {
                    vis[drow][dcol]=2;
                    q.push({{drow,dcol},t+1});
                    cnt++;
                }                
            }
        }
        if(cnt!=cnt_fr)
        return -1;
        return tm;
    }
};