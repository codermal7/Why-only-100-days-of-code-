class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int n=nums.size();
        int s=0,e=n-1,mid;
        while(s<=e)
        {
            mid=s+((e-s)/2);
            if(t==nums[mid])
                return mid;
            else if(t>nums[mid])
                s=mid+1;
            else
                e=mid-1;
        }
        return s;
    }
};