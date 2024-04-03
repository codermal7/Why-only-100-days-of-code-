class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; 
        mp[0]=-1;
        int sum = 0;
        int l_sub = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? - 1 : 1;    
            if(mp.find(sum) != mp.end())
            {
                if(l_sub < i - mp[sum])
                {
                    l_sub = i - mp[sum];
                }
            }
            else
            {
                mp[sum] = i;
            }
        }
        return l_sub;
    }
};