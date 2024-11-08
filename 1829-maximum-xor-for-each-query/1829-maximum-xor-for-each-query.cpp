class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res{};
        int n=nums.size(), limit=pow(2, maximumBit)-1;
        int prefix=accumulate(nums.begin(), nums.end(), 0, bit_xor<int>{});
        for(int i=n-1;i>=0;i--){
            res.push_back((prefix| limit)^ prefix);
            prefix^=nums[i];
        }
        return res;
    }
};