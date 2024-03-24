class Solution {
    public: int findDuplicate(vector < int > & nums) {
        // TC = O(n), SC = O(n);
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) 
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>1)
            return it.first;
        }
        return -1;

        // TC = O(nlog(n)), SC = O(1);
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // for (int i = 0; i < n - 1; i++) {
        //     if(nums[i] == nums[i + 1]) 
        //     {
        //         return nums[i];
        //     }
        // }
        // return -1;

        // TC = O(n), SC = O(1);
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};