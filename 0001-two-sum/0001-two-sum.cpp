class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;int n=nums.size(), complement;
        for (int i = 0; i < n; ++i) {
            complement = target - nums[i];
            if (mp.find(complement)!=mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};