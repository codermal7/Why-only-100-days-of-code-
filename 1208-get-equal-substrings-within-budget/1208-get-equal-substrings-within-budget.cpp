class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int maxLen = 0, currentCost = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentCost += abs(s[right] - t[right]);
            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};