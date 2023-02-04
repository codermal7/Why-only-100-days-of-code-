class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(),temp;bool swapped;vector<int> V(n);
        int l=0,r=n-1,index=n-1;
        while(l<=r)
        {
            if(abs(nums[l])>abs(nums[r]))
            {
                V[index]=nums[l]*nums[l];
                l++;
            }
            else
            {
                V[index]=nums[r]*nums[r];
                r--;
            }
            index--;                
        }
        return V;
    }
};