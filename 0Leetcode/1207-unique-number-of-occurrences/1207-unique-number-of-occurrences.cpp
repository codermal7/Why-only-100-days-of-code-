class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrenceCount;
        for (int num : arr) {
            occurrenceCount[num]++;
        }
        std::unordered_map<int, bool> occurrenceCheck;
        for (const auto& entry : occurrenceCount) {
            if (occurrenceCheck.count(entry.second) > 0) {
                return false;
            }
            occurrenceCheck[entry.second] = true;
        }

        return true;
    }
};