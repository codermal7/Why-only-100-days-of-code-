public class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(prices == null || prices.length <= 1)
            return 0;
        
        int[] bestBuy = new int[prices.length];
        int[] bestSell = new int[prices.length];
        int result = Integer.Min_Value;
        
        int min = prices[0];
        bestSell[0] = 0;
        for(int i=0; i<prices.length; i++) {
            bestSell[i] = prices[i] - min;
            min = prices[i] < min ? prices[i] : min;
        }
        
        int max = prices[prices.length-1];
        bestBuy[prices.length-1] = 0;
        for(int i=prices.length-1; i>=0; i--) {
            bestBuy[i] = max - prices[i];
            max = prices[i] > max ? prices[i] : max;
            
            bestSell[i] += bestBuy[i];
            result = bestSell[i] > result ? bestSell[i] : result;
        }
        return result;
    }
}