class Solution {
public:
    string removeStars(string &s) {
        int i = 0, k = 0;
        while(i < s.size()){
            if(s[i] != '*')
                s[k++] = s[i];
            else
                if(k > 0)k--;
            i++;
        }
        s.resize(k);
        return s;
    }
};