class Solution {
public:
    const int adj[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    vector<vector<int>> BFSDis(const vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    d[i][j] = 0;
                    q.push({i, j});
                }

        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int newX = x + adj[dir][0];
                    int newY = y + adj[dir][1];

                    if (newX < 0 || newX >= n) continue;
                    if (newY < 0 || newY >= n) continue;
                    if (d[newX][newY] != -1) continue;
                    
                    d[newX][newY] = d[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return d;
    }

    bool check(const vector<vector<int>>& d, int dis) {
        int n = d.size();

        if (d[0][0] < dis) 
            return false;

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<bool>> flag(n, vector<bool>(n, false));
        flag[0][0] = true;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1) return true;

            for (int dir = 0; dir < 4; dir++) {
                int newX = x + adj[dir][0];
                int newY = y + adj[dir][1];

                if (newX < 0 || newX >= n) continue;
                if (newY < 0 || newY >= n) continue;
                if (flag[newX][newY]) continue;
                if (d[newX][newY] < dis) continue;
                    
                flag[newX][newY] = true;
                q.push({newX, newY});
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> d = BFSDis(grid);
        
        int l = 0;
        int r = 2 * n;
        int res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(d, m)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
        
    }
};