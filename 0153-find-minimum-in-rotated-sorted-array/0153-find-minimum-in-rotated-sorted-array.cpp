class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,min=INT_MAX;

        while(s<=e)
        {
            int mid=s+((e-s)/2);
            // if(target==nums[mid])return true;
        
            //SORTED LEFT HALF
            if(nums[s]<=nums[mid])
            {
                if(nums[s]<min)
                min=nums[s];
                s=mid+1;
            }
            //SORTED RIGHT HALF
            else{
                if(nums[mid]<min)
                min=nums[mid];
                e=mid-1;
            }

        }
        return min;
    }
};