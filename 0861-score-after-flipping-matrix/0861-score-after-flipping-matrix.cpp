class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int r = 0; r < row; r++) {
            if (grid[r][0] == 0) {
                flipRow(grid, r);
            }
        }
        for (int c = 1; c < col; c++) {
            colOnes(grid, c);
        }
        int rowSum = 0;
        for (int r = 0; r < row; r++) {
            int currNum = 0;
            for (int c = 0; c < col; c++) {
                if (grid[r][col - 1 - c] == 1) {
                    currNum |= (1 << c);
                }
            }
            rowSum += currNum;
        }
        return rowSum;
    }
private:
    void colOnes(vector<vector<int>>& grid, int c) {
        int oneCnt = 0;
        for (int r = 0; r < grid.size(); r++) {
            if (grid[r][c] == 1) oneCnt++;
        }
        int zeroCnt = grid.size() - oneCnt;
        if (zeroCnt > oneCnt) flipCol(grid, c);
    }
    void flipRow(vector<vector<int>>& grid, int r) {
        for (int c = 0; c < grid[0].size(); c++) {
            grid[r][c] = (grid[r][c] == 1) ? 0 : 1;
        }
    }
    void flipCol(vector<vector<int>>& grid, int c) {
        for (int r = 0; r < grid.size(); r++) {
            grid[r][c] = (grid[r][c] == 1) ? 0 : 1;
        }
    }
};