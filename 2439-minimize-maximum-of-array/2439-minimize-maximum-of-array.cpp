class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int ans =0,res=0;int n=nums.size();
        for(int i=0;i<n;i++){
            res  = res + nums[i];
            ans = max(ans,(res+i)/(i+1));
        }
        return ans;
    }
};