class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        int n = arr.size();
        vector<int> countOfFrequencies(n + 1, 0);
        for (auto it : map) {
            countOfFrequencies[it.second]++;
        }
        int remainingUniqueElements = map.size();
        for (int i = 1; i <= n; i++) {
            int numElementsToRemove = min(k / i, countOfFrequencies[i]);
            k -= (i * numElementsToRemove);
            remainingUniqueElements -= numElementsToRemove;
            if (k < i) {
                return remainingUniqueElements;
            }
        }
        return 0;
    }
};