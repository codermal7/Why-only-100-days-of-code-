class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), dir = 0; // direction
        vector<int> result(m * n), curr = {0, 0}; // {r, c}
        vector<vector<int>> limit = {{0, n - 1}, {m - 1, n - 1}, {m - 1, 0}, {1, 0}},
        dCurr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, // {dr, dc}
        dLimit = {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}}; // change in boundaries
        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[curr[0]][curr[1]];
            if (curr == limit[dir]) { // change direction
                limit[dir] = {limit[dir][0] + dLimit[dir][0], limit[dir][1] + dLimit[dir][1]};
                dir = (dir + 1) % 4;
            }
            curr = {curr[0] + dCurr[dir][0], curr[1] + dCurr[dir][1]};
        }
        return result;
    }
};