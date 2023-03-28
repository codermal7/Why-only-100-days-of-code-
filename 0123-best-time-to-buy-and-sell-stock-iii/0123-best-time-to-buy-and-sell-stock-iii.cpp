class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,vector<vector<vector<int>>> &memo)
    {   
        //if buy =1 means we have to buy now
        //else we have to sell now
        if(ind>=prices.size()||c>=2) return 0; //counter
        if(memo[ind][buy][c]!=-1) return memo[ind][buy][c];
        if(buy) //now we can either buy prices[i] or we can skip it and try next to buy
        {
            return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,memo),find(prices,ind+1,buy,c,memo));
        }
        else  //now we can either sell prices[i] or we can skip it and try next to sell
        {
            return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,memo),find(prices,ind+1,buy,c,memo));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        //here we can do maximum two transaction
        //Use 3-D vector because here three states i,k,buy/sell
        vector<vector<vector<int>>> memo(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
          
       return find(prices,0,1,0,memo); 
    }
};