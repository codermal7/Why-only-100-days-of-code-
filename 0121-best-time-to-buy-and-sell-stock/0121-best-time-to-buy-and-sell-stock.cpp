class Solution {
public:
    int find(vector<int> &prices, int i,int k,bool buy,vector<vector<int>> &v)
    {
        //if we have no stock or we have no chance of transaction(k=0)
        if(i>=prices.size()||k<=0) return 0;
        if(v[i][buy]!=-1) return v[i][buy];
        
        if(buy)  //if we are buying then next time we will sell else next time we will buy
        {        //-prices[i], because bought stock of prices[i], expend money
            
           return v[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v)); 
        }
        else    //it's time to sell , now decrease k, we have done 1 transaction
        {       //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
           return v[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v),find(prices,i+1,k,buy,v)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(); 
        vector<vector<int>> v(n,vector<int> (2,-1));
        //passing here buy=1 because we will first buy then sell
        //we can do atmost k=1 transaction
        return find(prices,0,1,1,v);
    }
};
