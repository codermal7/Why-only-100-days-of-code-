class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] == 1) {
                return i;
            }
        }
        return -1;

        // int n=s.length();
        // for (int i = 0; i < n; i++) {
        //     bool repeated = false;
        //     for (int j = 0; j < n; j++) {
        //         if (i != j && s[i] == s[j]) {
        //             repeated = true;
        //             break;
        //         }
        //     }
        //     if (!repeated) {
        //         return i;
        //     }
        // }
        // return -1;

        // std::unordered_map<char, int> frequencyMap;
        // std::queue<std::pair<char, int>> charQueue;

        // for (int i = 0; i < s.size(); i++) {
        //     frequencyMap[s[i]]++;
        //     charQueue.push(std::make_pair(s[i], i));
        // }

        // while (!charQueue.empty()) {
        //     char currentChar = charQueue.front().first;
        //     int currentIndex = charQueue.front().second;
        //     if (frequencyMap[currentChar] == 1) {
        //         return currentIndex;
        //     } else {
        //         charQueue.pop();
        //     }
        // }
        // return -1;
    }
};