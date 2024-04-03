class Solution {
public:
    int firstO(vector<int>& nums, int n, int k){
        int s=0,e=n-1,first=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(k==nums[mid]){
                first=mid;
                e=mid-1;
            }
            else if(k<nums[mid])
            e=mid-1;
            else
            s=mid+1;
        }
        return first;
    }
    int lastO(vector<int>& nums, int n, int k){
        int s=0,e=n-1,last=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(k==nums[mid]){
                last=mid;
                s=mid+1;
            }
            else if(k<nums[mid])
            e=mid-1;
            else
            s=mid+1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int k) {
        int n=nums.size();
        int first=(firstO(nums,n,k));
        if(first==-1)
        return {-1,-1};
        int last=(lastO(nums,n,k));
        return {first,last};
    }
};