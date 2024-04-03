class Solution {
public:
    string getHint(string secret, string guess) {
        int count[10] = {0};
        int bull = 0, cow = 0;
        
        for (int i = 0; secret[i]; i ++) {
            if (secret[i] == guess[i]) bull ++;
            else {
                cow += (count[secret[i] - '0'] ++ < 0);
                cow += (count[guess[i] - '0'] -- > 0);
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};