class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();int c;
        vector<int> nums1;vector<vector<int>> ans;
        if(n%3!=0)
        return {{}};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i+=3)
        {
            if(nums[i+2]-nums[i]>k)
            return {};
            else
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};