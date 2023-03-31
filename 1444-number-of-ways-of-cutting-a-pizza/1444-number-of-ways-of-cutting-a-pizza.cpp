class Solution {
public:
    const int MOD = 1e9 + 7;
    int ways(vector<string>& pizza, int k) {
    int m = pizza.size();
    int n = pizza[0].size();
    
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            dp[i][j] = (pizza[i][j] == 'A') ? 1 : 0;
            if (i + 1 < m) dp[i][j] += dp[i + 1][j];
            if (j + 1 < n) dp[i][j] += dp[i][j + 1];
            if (i + 1 < m && j + 1 < n) dp[i][j] -= dp[i + 1][j + 1];
        }
    }
    
    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

    function<int(int, int, int)> dfs = [&](int i, int j, int p) {
        if (p == 1) return dp[i][j] > 0 ? 1 : 0;
        if (dp[i][j] < p) return 0;
        if (memo[i][j][p] != -1) return memo[i][j][p];
    
        int ans = 0;

        for (int r = i + 1; r < m; r++) {
            if (dp[i][j] - dp[r][j] > 0) {
                ans += dfs(r, j, p - 1);
                ans %= MOD;
            }
        }

        for (int c = j + 1; c < n; c++) {
            if (dp[i][j] - dp[i][c] > 0) {
                ans += dfs(i, c, p - 1);
                ans %= MOD;
            }
        }

        memo[i][j][p] = ans;
        return ans;
    };

    return dfs(0, 0, k);
}
};