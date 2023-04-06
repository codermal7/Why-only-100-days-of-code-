class Solution {
    void util(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j])
            return;
        grid[i][j] = 1;
        util(grid,i-1,j);
        util(grid,i,j-1);
        util(grid,i+1,j);
        util(grid,i,j+1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++)
            util(grid,i,0), util(grid,i,m-1);
        for(int j=0; j<m; j++)
            util(grid,0,j), util(grid,n-1,j);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!grid[i][j])
                    util(grid,i,j), c++;
        return c;
    }
};