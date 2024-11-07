class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            cnt = 0;
            for (auto can : candidates) {
                if (can & (1 << i))
                    cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};