#define ll long long
const int M = 1e9+7;
const int N = 1e5+10;
int dp[N];
class Solution {
public:
    ll late(ll n){
        if(n == 1) return 2;
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        ll a,b,c; a=c=0; b=1;
        // 1 day late or not late
        a = late(n-2);
        c = late(n-1);

        // late 2 days
        if(n>2)
        b = late(n-3);

        return dp[n] = (a+b+c) % M;
    }

    int checkRecord(int n) {
        fill(dp,dp+N, -1);

        ll ans = late(n);
        for(int i=0; i<n; i++){
            ans = (ans + ( late(i) * late(n-i-1) %M) ) %M;
        }

        return ans;
    }
};