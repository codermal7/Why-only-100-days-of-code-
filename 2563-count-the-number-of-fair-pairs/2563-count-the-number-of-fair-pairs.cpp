class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            auto lowerIt = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto higherIt = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            higherIt--;
            if (lowerIt <= higherIt) {
                cnt += higherIt - lowerIt + 1;
            }
        }
        return cnt;
    }
};