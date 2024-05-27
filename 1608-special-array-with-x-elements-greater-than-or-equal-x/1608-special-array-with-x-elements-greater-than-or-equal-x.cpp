class Solution {
public:
    int specialArray(vector<int>& nums) {
        int ans=-1;
        int low=-1;
        int high=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            int ct=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>=mid){
                    ct++;
                }
            }
            if(ct==mid){
                return mid;
            }else if(ct>mid){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
        
    }
};