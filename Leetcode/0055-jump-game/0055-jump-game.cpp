class Solution {
public:
    bool canJump(vector<int>& nums) {
        int min_to_reach = nums.size() - 1, i;
        
        for(i = nums.size() - 2; i >=0; i--) {
            if(nums[i] + i >= min_to_reach)
                min_to_reach = i;
        }
        if(min_to_reach == 0)
            return true;
        else
            return false;
    }
};