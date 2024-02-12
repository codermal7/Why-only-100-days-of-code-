class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();int c=1;
        for(int i=0;i<n;i++)
        {
            c=1;
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j])
                c++;
            }
            if(c>n/2)
            return nums[i];
        }
        return c;
    }
};