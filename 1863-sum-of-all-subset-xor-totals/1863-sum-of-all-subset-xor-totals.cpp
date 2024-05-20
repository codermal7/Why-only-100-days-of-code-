class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int x = pow(2, n - 1);
        int bit = 0;
        for (int i = 0; i < n; i++) {
            bit |= nums[i];
        }
        return (bit) * (x);
    }
};