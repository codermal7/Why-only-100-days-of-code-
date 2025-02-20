class Solution {
public:
    string result;
    unordered_set<string> seen;
    void generateUnique(const string& current, size_t length, bool& found) {
        if (length == 0) {
            if (!seen.count(current)) {
                found = true;
                result = current;
            }
            return;
        }
        if (!found)
            generateUnique(current + "0", length - 1, found);
        if (!found)
            generateUnique(current + "1", length - 1, found);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        seen = unordered_set<string>(nums.begin(), nums.end());
        bool found = false;
        generateUnique("", nums.size(), found);
        return result;
    }
};
