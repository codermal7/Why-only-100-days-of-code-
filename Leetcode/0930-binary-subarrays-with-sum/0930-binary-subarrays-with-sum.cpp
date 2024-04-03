class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubArrs(nums,goal)-countSubArrs(nums,goal-1);
    }
    int countSubArrs(vector<int>&nums,int sum){
        if(sum<0) return 0;
        int preSum=0,j=0,count=0;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            while(preSum>sum){
                preSum-=nums[j++];
            }
            count+=(i-j+1);
        }
        return count;
    }
};