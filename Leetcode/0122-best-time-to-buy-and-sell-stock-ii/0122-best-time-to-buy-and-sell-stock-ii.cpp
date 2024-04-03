class Solution {
public:
int find(int ind,vector<int> &v,bool buy,vector<vector<int>> &memo)
{    
    if(ind>=v.size()) return 0;
    if(memo[ind][buy]!=-1) return memo[ind][buy];
    
    if(buy) //if we are buying then next time we will sell else next time we will buy
    {      //-prices[i], because bought stock of prices[i], expend money, !buy because next time sell
        
       return memo[ind][buy]=max(-v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));  
    }
    else   //it's time to sell 
    {      //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
        
       return memo[ind][buy]=max(v[ind]+find(ind+1,v,!buy,memo),find(ind+1,v,buy,memo));  
    }
     
}
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n<2) return 0;
        vector<vector<int>> v(n+1,vector<int>(2,-1));
        //passing here buy=1 because we will first buy then sell 
        return find(0,prices,1,v); 
    }
};
