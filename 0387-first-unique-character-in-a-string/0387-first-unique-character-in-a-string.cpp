class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char,int> mp;
        // for(char ch:s)
        // {
        //     mp[ch]++;
        // }
        // for (int i = 0; i < s.length(); i++) {
        //     if (mp[s[i]] == 1) {
        //         return i;
        //     }
        // }
        // return -1;

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

        unordered_map<char, int> count;
        queue<char> q;

        for (char c : s) {
            count[c]++;
            q.push(c);

            while (!q.empty() && count[q.front()] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : find(s.begin(), s.end(), q.front()) - s.begin();
    }
};