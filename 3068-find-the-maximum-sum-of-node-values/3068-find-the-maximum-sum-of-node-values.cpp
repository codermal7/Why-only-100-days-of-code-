class Solution {
public:
#define ll long long
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        ll sum = 0, cnt = 0;
        for (auto& i : nums) {
            if ((i ^ k) > i)
                cnt++, i ^= k;
            sum += i;
        }
        if (cnt & 1) {
            int mn = 1e9;
            for (auto i : nums)
                mn = min(mn, i - (i ^ k));
            sum -= mn;
        }
        return sum;
    }
};