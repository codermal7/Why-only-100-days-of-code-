//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    long long int m =1000000007;
    int disp(vector<int> &dp,int n)
    {
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n]%m;
        return (dp[n]=(disp(dp,n-1)+disp(dp,n-2))%m);
    }
    
    int countWays(int n)
    {
        vector<int> dp(n+1,-1);
        // if(n<=1)return 1;
        
        // long a=1,b=1;long c;
        // for(int i=2;i<=n;i++)
        // {
        //     c=(a+b)%m;
        //     a=b;
        //     b=c;
        // }
        // return c%m;
        return disp(dp,n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends