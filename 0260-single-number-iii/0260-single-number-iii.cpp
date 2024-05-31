class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return nums;
        sort(nums.begin(),nums.end());
        vector<int>v;
        int i=0;
        while(i<n){
            if(i==n-1){
                if(nums[n-1]!=nums[n-2]) v.push_back(nums[n-1]);
                break;
            }
            if(nums[i]==nums[i+1]){
                i=i+2;
            }
            else if(nums[i]!=nums[i+1]){
                v.push_back(nums[i]);
                i++;
            }
        }
        return v;
        
    }
};