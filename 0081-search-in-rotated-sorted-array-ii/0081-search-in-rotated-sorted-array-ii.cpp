class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int s=0,e=nums.size()-1,mid;
        while(s<=e)
        {
            mid=s+((e-s)/2);
            if(target==nums[mid])
            return true;
            else if(target>nums[mid])
            s=mid+1;
            else
            e=mid-1;
        }
        return false;
    }
};