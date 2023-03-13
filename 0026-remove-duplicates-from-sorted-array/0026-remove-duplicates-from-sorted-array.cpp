class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n=nums.size();
        // set<int> set1;
        // for (const int &i: nums) 
        // {
        //     set1.insert(i);
        // }int a=0;
        // for (const int &i: set1) 
        // {
        //     nums[a]=i;
        //     a++;
        // }
        // return set1.size();
        int count = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        return n-count;
    }
};