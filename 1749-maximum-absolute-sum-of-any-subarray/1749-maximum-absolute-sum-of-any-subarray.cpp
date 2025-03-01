class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size(); int sum=0, sum2=0, maxi=INT_MIN, mini=INT_MAX;

        // FINDING MINIMUM -VE SUM
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mini=min(mini,sum);
            if(sum>0)
            sum=0;
        }

        // FINDING MAXIMUM +VE SUM
        for(int i=0;i<n;i++)
        {
            sum2+=nums[i];
            maxi=max(maxi,sum2);
            if(sum2<0)
            sum2=0;
        }

        return max(abs(mini), maxi);
    }
};