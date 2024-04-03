class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 || i >=m || j<0 || j>=n || grid[i][j] == 0 || grid[i][j] == 2) return;
        grid[i][j] = 2;
        int ai[] = {0,1,0,-1};
        int aj[] = {1,0,-1,0};

        for(int k=0;k<4;k++){
            dfs(grid,i+ai[k],j+aj[k],m,n);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            dfs(grid,i,0,m,n);
            dfs(grid,i,n-1,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(grid,0,i,m,n);
            dfs(grid,m-1,i,m,n);
        }

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }

        return count;
    }
};