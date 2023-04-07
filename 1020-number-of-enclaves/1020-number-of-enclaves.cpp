class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &grid){
        grid[row][col] = 0;
        int delr[] = {0,0,-1,1};
        int delc[] = {-1,1,0,0};

        for(int i = 0;i<4;i++){
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid)
    {
      int n = grid.size();
      int m = grid[0].size();

      int ans = 0;

      for(int i = 0;i<n;i++){
          for(int j = 0;j<m;j++){
              if(i==0 || j==0 || i==n-1 || j==m-1){
                  if(grid[i][j]==1){
                      dfs(i,j,grid);
                  }
              }
          }
      }

      for(int i = 0;i<n;i++){
          for(int j = 0;j<m;j++){
              if(grid[i][j]==1)
              ans++;
          }
      }

    return ans;
    } 
};