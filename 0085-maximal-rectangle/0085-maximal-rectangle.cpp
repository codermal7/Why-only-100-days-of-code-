class Solution {
public:
    int dfs(int i,int j,vector<vector<char>>& matrix,vector<vector<int>>& dp){
        int n = matrix.size();
        int m = matrix[0].size();
        if(i<0 or j<0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(matrix[i][j] == '1'){
            ans = 1+dfs(i-1,j,matrix,dp);
        }
        else{
            ans = 0;
        }
        return dp[i][j] = ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == -1) {
                    dfs(i, j, matrix, dp);
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = dp[i][j];
                for(int k=j;k<m;k++){
                    x = min(x,dp[i][k]);
                    res = max(res,(k-j+1)*x);
                }
            }
        }
        return res;
    }
};