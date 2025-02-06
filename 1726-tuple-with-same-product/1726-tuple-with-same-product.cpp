class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int size = nums.size();
        int count = 0;
        sort(nums.begin() , nums.end());
        unordered_map<long long , int> mp;
        for(int i = 0 ; i < size ; i++)
        {
            for(int j = i + 1 ; j < size; j++)
            {
                long long prod = nums[i] * nums[j];
                if(mp.find(prod) != mp.end())
                {
                    count += mp[prod] * 8;
                }
                mp[prod]++;
            }
        }
        return count;
        }
};