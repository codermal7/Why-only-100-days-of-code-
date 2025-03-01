class Solution {
public:
    vector<vector<int>>result;
    void findtrip(vector<int>& nums, int i, int j, int target)
    {
        while(i<j)
        {
            if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else if(nums[i]+nums[j]<target)
            {
                i++;
            }
            else
            {
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        return {};
        result.clear();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int n1=nums[i]; int target=-n1;
            findtrip(nums,i+1,n-1,target);
        }
        return result;
    }
};