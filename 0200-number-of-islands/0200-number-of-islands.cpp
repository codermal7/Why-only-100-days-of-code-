class Solution {
public:
void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> grid,int n,int m)
    {
        vis[row][col]=1;int drow,dcol;
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto d : dir) {
                int drow = row + d.first;
                int dcol = col + d.second;
                if(drow>=0 && drow<n && dcol>=0 && dcol<m 
                && grid[drow][dcol]=='1' && !vis[drow][dcol])
                {
                    vis[drow][dcol]=1;
                    q.push({drow,dcol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,vis,grid,n,m);
                }
            }
        }
        return cnt;
    }
};