class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n=nums.size();int c=1;
        // for(int i=0;i<n;i++)
        // {
        //     c=1;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(nums[i]==nums[j])
        //         c++;
        //     }
        //     if(c>n/2)
        //     return nums[i];
        // }
        // return c;
        // sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i:nums)
        mp[i]++;
        for(auto it:mp)
        {
            if(it.second>n/2)
            return it.first;
        }
        return -1;
    }
};