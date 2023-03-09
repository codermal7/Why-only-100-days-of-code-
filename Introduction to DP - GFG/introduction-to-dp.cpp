//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
long long int MOD=1e9+7;

long long int dp[100001];

class Solution {

  public:

    long long int topDown(int n) {

      if(n==0) return dp[0]=0;

      if(n==1) return dp[1]=1;

      if(dp[n]!=-1) return dp[n];

      return (dp[n]=topDown(n-1)+topDown(n-2))%MOD;

    }

    long long int bottomUp(int n) {

        vector<long long int> dp(n+1);

        dp[0]=0;

        dp[1]=1;

        for(int i=2;i<=n;i++){

            dp[i]=(dp[i-1]+dp[i-2])%MOD;

        }

        return dp[n]%MOD;

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends