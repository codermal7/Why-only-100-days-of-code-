class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int p = nums.size();
        vector<int> smm(p);
        smm[p - 1] = nums[p - 1];
        
        for (int i = p - 2; i >= 0; --i) {
            smm[i] = max(nums[i], smm[i + 1]);
        }
        
        long long disp = 0;
        for (int i = 0; i < p - 2; ++i) {
            for (int j = i + 1; j < p - 1; ++j) {
                disp = max(disp, (long long)(nums[i] - nums[j]) * smm[j + 1]);
            }
        }
        
        return disp;
    }
};