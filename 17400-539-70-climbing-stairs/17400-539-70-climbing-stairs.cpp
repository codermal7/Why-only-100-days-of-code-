class Solution {

public:

    int disp(vector<int> &dp,int n)

    {

        if(n<=1)

            return 1;

        if(dp[n]!=-1)

            return dp[n];

        return (dp[n]=disp(dp,n-1)+disp(dp,n-2));

    }

    

    int climbStairs(int n) {

        vector<int> dp(n+1,-1);

        return disp(dp,n);

    }

};
