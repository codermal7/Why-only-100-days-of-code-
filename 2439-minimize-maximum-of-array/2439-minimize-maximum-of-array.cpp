class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int ans =0;int n=nums.size();
        long long int total =0;
        for(int i=0;i<n;i++){
         total  = total + nums[i];
            ans = max(ans,(total+i)/(i+1));

        }
        return ans;
    }
};