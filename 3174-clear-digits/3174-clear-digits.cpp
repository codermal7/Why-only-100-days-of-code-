class Solution {
public:
    string clearDigits(string s) {
        string res; int len =s.size();
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i]) && !res.empty())
            {
                res.pop_back();
            } 
            else
            {
                res+= s[i];
            }
        }
        return res;
    }
};