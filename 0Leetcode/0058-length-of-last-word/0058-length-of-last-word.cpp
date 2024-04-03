class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0; bool charfound = false;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                charfound = true;
                c++;
            }
            else if(charfound==true) {
                break;
            }
        }
        
        return c;
    }
};