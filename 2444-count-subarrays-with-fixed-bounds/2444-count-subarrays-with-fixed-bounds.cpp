class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> data(3, -1);
        long long ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                data[0] = -1; 
                data[1] = -1;
                data[2] = i;
                continue;
            }
            if (nums[i] == minK) data[0] = i;
            if (nums[i] == maxK) data[1] = i;
            if (data[0] != -1 && data[1] != -1) ans += min(data[0],data[1]) - data[2];
        }

        return ans;

    }
};