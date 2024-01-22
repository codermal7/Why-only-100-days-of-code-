class Solution {
public:
    int result(int i, int j, string& a, string& b, vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=1+result(i-1,j-1,a,b,dp);
        return dp[i][j]=max(result(i-1,j,a,b,dp),result(i,j-1,a,b,dp));
    }
    int longestCommonSubsequence(string a, string b) {
        int n=a.length(),m=b.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return result(n-1,m-1,a,b,dp);;
    }
};