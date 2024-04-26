class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int minIdx1 = 0;
        int minIdx2 = n-1;        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] < grid[i][minIdx1]){
                    minIdx2 = minIdx1;
                    minIdx1 = j;
                }
                else if(grid[i][j] < grid[i][minIdx2] && j != minIdx1)
                    minIdx2 = j;
            }
            for(int j = 0; j < n; j++){
                if(i+1 < n){
                    if(j == minIdx1)
                        grid[i+1][j] += grid[i][minIdx2];
                    else
                        grid[i+1][j] += grid[i][minIdx1];                   
                }
            }
        }
        return grid[n-1][minIdx1];
    }
};