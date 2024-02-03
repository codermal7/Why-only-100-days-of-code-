class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for (int i = 0; i < nums.size(); i++) 
        // {
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp)
        // {
        //     if(it.second>1)
        //     return it.first;
        // }
        // return -1;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) 
            {
                return nums[i];
            }
        }
        return -1;
    }
};