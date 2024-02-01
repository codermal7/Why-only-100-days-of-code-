class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();vector<int> ans(n);
        int l=0,h=n-1,lastplaceindex=n-1;
        while(l<=h)
        {
            int ls=nums[l]*nums[l];
            int hs=nums[h]*nums[h];
            if(ls>hs)
            {
                ans[lastplaceindex--]=ls;
                l++;
            }
            else
            {
                ans[lastplaceindex--]=hs;
                h--;
            }
        }
        return ans;
    }
};