//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid, int n, int m)
    {
        vis[row][col]=1;int drow,dcol;
        queue<pair<int, int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    drow=row+i;
                    dcol=col+j;
                    if(drow>=0 && drow<n && dcol>=0 && dcol<m 
                    && grid[drow][dcol]=='1' && !vis[drow][dcol])
                    {
                        vis[drow][dcol]=1;
                        q.push({drow,dcol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends