class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        bitset<2048> seen;

        for (int num : nums) {
            const int abs_num = abs(num);
            if (abs_num > ans && seen[-num + 1024])
                ans = abs_num;
            seen[num + 1024] = true;
        }

        return ans;
    }
};