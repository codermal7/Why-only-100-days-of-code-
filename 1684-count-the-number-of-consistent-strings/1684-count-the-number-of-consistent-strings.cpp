class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> match(allowed.begin(), allowed.end());
        int cnt = 0;
        for (auto it : words) {
            bool foundall = true;
            for (char ch : it) {
                if (match.find(ch) == match.end()) {
                    foundall = false;
                    break;
                }
            }

            if (foundall) {
                cnt++;
            }
        }
    return cnt;
    }
};