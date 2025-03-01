class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int n=nums.size(); int sum=0, maxi=INT_MIN;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=nums[i];
        //     maxi=max(maxi,sum);
        //     if(sum<0)
        //     sum=0;
        // }
        // return maxi;
        int maxSum = nums[0], currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]); 
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};