class Solution {
public:
    int appendCharacters(std::string s, std::string t) {
        int n = s.length();
        int m = t.length();
        
        int ts = 0;

        for (int ps = 0; ps < n; ++ps) {
            if (ts < m && s[ps] == t[ts]) {
                ++ts;
            }
        }
        
        return m - ts;
    }
};