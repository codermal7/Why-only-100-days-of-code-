class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        int duplicate = -1, missing = -1;

        for (int num : nums) {
            if (numSet.find(num) != numSet.end()) {
                duplicate = num;
            } else {
                numSet.insert(num);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (numSet.find(i) == numSet.end()) {
                missing = i;
                break;
            }
        }
        return {duplicate, missing};
    }
};


