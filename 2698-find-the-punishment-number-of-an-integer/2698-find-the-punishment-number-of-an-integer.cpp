class Solution {
public:
    bool split(int sum, int rem, int tgt) {
        if (sum == tgt && rem == 0) 
            return true;
        if (sum > tgt) 
            return false;

        for (int len = 1; rem / (int)pow(10, len - 1) > 0; len++) {
            int part = rem % (int)pow(10, len);
            if (split(sum + part, rem / (int)pow(10, len), tgt)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) { 
            int sqr = i * i;
            if (split(0, sqr, i)) {
                ans+=sqr;
            }
        }
        return ans;
    }
};