class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int, int> um;
        for (int x : nums) {
            um[x]++;
        }
        int maxi = 0;
        for (auto x : um) {
            if (x.second > maxi) {
                maxi = x.second;
            }
        }
        int ans = 0;
        for (auto x : um) {
            if (x.second == maxi) {
                ans += maxi;
            }
        }
        return ans;
    }
};