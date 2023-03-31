class Solution {
public:
    int n, m;
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int f(vector<string> &a, int k, int i, int j){
        
        // base cases 
        if(k == 1){
            for(int ti = i; ti <= n-1; ti++){
                for(int tj = j; tj <= m-1; tj++){
                    if(a[ti][tj] == 'A') return 1;
                }
            }

            return 0;
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];


        int res = 0;
        // horizontal cut 
        int flag = 0;
        for(int indx = i+1; indx <= n-1; indx++){
            // finding whether an apple is there 

            if(flag == 0){
                for(int tj = j; tj <= m-1; tj++){
                    if(a[indx-1][tj] == 'A'){
                        flag = 1;
                        break;
                    }
                }
            }

            if(flag){
                res =  (res + f(a, k-1, indx, j))%mod;
            }

        }

        // vertical cut 
        flag = 0;
        for(int indx = j+1; indx <= m-1; indx++){
            // finding whether an apple is there 

            if(flag == 0){
                for(int ti = i; ti  <= n-1; ti++){
                    if(a[ti][indx-1] == 'A'){
                        flag = 1;
                        break;
                    }
                }
            }

            if(flag){
                res =  (res + f(a, k-1, i, indx))%mod;
            }
        }

        return dp[i][j][k] = res% mod;
    }
    int ways(vector<string>& a, int k) {
        n = a.size();
        m = a[0].size();

        dp.resize(n+1, vector<vector<int>> (m+1, vector<int> (k+1, -1)));
        return f(a, k, 0, 0);
    }
};