class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int index = 1;
        int ans = 1;

        int increasingLength = 1, decreasingLength = 1;
        while(index < nums.size()){
            if(nums[index] > nums[index - 1]){
                increasingLength++;
                decreasingLength = 1;
            } else if(nums[index] < nums[index - 1]){
                decreasingLength++;
                increasingLength = 1;
            } else {
                increasingLength = 1;
                decreasingLength = 1;
            }

            ans = max(ans, (max(increasingLength, decreasingLength)));
            index++;
        }

        return ans;
    }
};