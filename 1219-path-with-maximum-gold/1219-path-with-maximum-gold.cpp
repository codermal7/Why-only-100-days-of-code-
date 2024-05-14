class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    int maxGold = 0;

    void dfs(vector<vector<int>>& grid, int count, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;

        if (grid[i][j])
        {
            int cur = grid[i][j];
            count += cur;
            grid[i][j] = 0;

            maxGold = max(maxGold, count);
            for (int k = 0; k < 4; k++)
            {
                int newX = i + x[k];
                int newY = j + y[k];

                dfs(grid, count, newX, newY);
            }
            grid[i][j] = cur;
        }
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j]) 
                    dfs(grid, 0, i, j);
            }
        }

        return maxGold;
    }
};