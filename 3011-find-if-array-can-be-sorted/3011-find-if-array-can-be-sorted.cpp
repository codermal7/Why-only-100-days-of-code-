class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int prev =INT_MIN;

        int currmax = nums[0];
        int currmin = nums[0];
        int bitn = __builtin_popcount(nums[0]);

        int i=1;
        while(i<nums.size()){
            while( i<nums.size() && __builtin_popcount(nums[i])==bitn ){
                currmax = max(currmax, nums[i]);
                currmin = min(currmin, nums[i]);
                i++;
            }
            if(prev > currmin){
                return false;
            }else if(i<nums.size()){
                prev = currmax;
                currmax = nums[i];
                currmin = nums[i];
                bitn = __builtin_popcount(nums[i]);
            }
        }
        return true;
    }
};