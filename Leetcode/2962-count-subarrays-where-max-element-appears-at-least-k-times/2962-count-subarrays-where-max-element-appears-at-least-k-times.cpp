class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=INT_MIN;
        for(auto it : nums){
            mx=max(mx,it);
        }
        int n=nums.size();
        int freq=0;
        int start=0;
        long long ans=0;
        for(int end=0;end<n;end++){
            if(nums[end]==mx)
                freq++;
            while(freq==k){
                if(nums[start]==mx)
                    freq--;
                start++;
            }
            ans+=start;
        }
        return ans;
    }
};