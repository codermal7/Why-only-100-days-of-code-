class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& a) {        
        int result = 0, sum1 = 0, oddsum = 0, evensum = 1; 

        for (auto it : a) {
            sum1 += it;
            if (sum1 % 2 == 0) {
                result = (result + oddsum) % mod;
                evensum++;
            } else {
                result = (result + evensum) % mod;
                oddsum++;
            }
        }
        return result;
    }
};