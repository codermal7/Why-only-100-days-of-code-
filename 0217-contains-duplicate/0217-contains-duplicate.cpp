class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            if(it.second>1)
            return true;
        }
        return false;
    }
};