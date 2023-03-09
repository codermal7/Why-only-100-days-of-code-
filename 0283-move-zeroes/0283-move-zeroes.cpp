class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int n=nums.size();
    //     int l=0,r=1,c=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i]==0)
    //             c++;
    //     }
    //     if(c!=n || (n!=2 && nums[1]==0) )
    //     {
    //         while(r<n)
    //         {
    //             if(nums[r]!=0 && l!=r)
    //             {
    //                 int temp=nums[r];
    //                 nums[r]=nums[l];
    //                 nums[l]=temp;
    //                 r++;l++;
    //             }
    //             else if(nums[l]==0 && nums[r]==0 && r<n-1)
    //             {
    //                 r++;
    //             }
    //         }
    //     }
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(j<n){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==0 && nums[j]==0){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
};