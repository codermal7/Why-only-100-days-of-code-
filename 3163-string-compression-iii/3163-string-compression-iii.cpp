class Solution {
public:
    string compressedString(string word) {
        int count = 1;
        string comp = "";
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == word[i + 1]) {
                
                if (count == 9) {
                    comp += to_string(count);
                    comp += word[i];
                    count = 0;
                }
                count++;
            } else {
                comp += to_string(count);
                comp += word[i];
                count=1;
                
            }
        }
        return comp;
    }
};