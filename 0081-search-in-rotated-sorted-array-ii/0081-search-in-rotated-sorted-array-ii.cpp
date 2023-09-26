// log n solution

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int s=0,e=nums.size()-1,mid;

        while(s<=e)
        {
            mid=s+((e-s)/2);
            if(target==nums[mid])return true;
            if(nums[s]==nums[mid] && nums[mid]==nums[e])
            {
                s++;e--;continue;
            }
            //SORTED LEFT HALF
            else if(nums[s]<=nums[mid])
            {
                if(nums[s]<=target && target<=nums[mid])
                e=mid-1;
                else
                s=mid+1;
            }
            //SORTED RIGHT HALF
            else{
                if(nums[mid]<=target && target<=nums[e])
                s=mid+1;
                else
                e=mid-1;
            }

        }
        return false;
    }
};