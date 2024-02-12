class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size(), c=0;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]==c)
        //     {
        //         c++;
        //         continue;
        //     }
        //     else
        //     {
        //         return c;
        //     }
        // }
        // return c;
        // unordered_map<int, bool> mp;
        // for (int num : nums) {
        //     mp[num] = true;
        // }
        // int n = nums.size();
        // for (int i = 0; i <= n; i++) {
        //     if (mp.find(i) == mp.end()) {
        //         return i;
        //     }
        // }
        // return n;
        int sum=0,n=nums.size() ;
        int range_sum= n*(n+1)/2;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        return (range_sum-sum);
    }
};