// MOST OPTIMIZED

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,ans=INT_MAX;

        while(s<=e)
        {
            int mid=s+((e-s)/2);
            if(nums[s]<nums[e]){
                ans=min(nums[s],ans);
                break;
            }
        
            //SORTED LEFT HALF
            if(nums[s]<=nums[mid])
            {
                ans=min(nums[s],ans);
                s=mid+1;
            }
            //SORTED RIGHT HALF
            else{
                ans=min(nums[mid],ans);
                e=mid-1;
            }

        }
        return ans;
    }
};