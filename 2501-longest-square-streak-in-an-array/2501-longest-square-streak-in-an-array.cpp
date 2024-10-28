class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int longsec=0;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (auto it : nums) {
            int root = (int)sqrt(it);
            if (root * root == it &&
                mp.find(root) != mp.end()) {
                mp[it] = mp[root] + 1;
            } else {
                mp[it] = 1;
            }
        }
        for (auto& [key, mp] : mp) {
            longsec = max(longsec, mp);
        }
        if(longsec==1)
        return -1;
        else 
        return longsec;
    }
};