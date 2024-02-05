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
    }
};