class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0 , end = 0;
        unordered_map<int,int> map;
        int maxi = INT_MIN , n = nums.size();

        if(n==1) {
            return 1;
        }

        if(n==2) {
            if(nums[0] == nums[1] && k == 1)
            return 1;
            else 
            return 2;
        }

        while(end < n) {
            
            if(map[nums[end]] < k) {
               map[nums[end++]]++;
            }
            else {
                maxi = max(maxi , end - start);
                map[nums[start++]]--;
            }
        }

        maxi = max(maxi  , end - start);

        return maxi;
    }
};