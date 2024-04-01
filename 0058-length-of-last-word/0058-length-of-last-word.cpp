// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int c=0, n=s.size();
//         string word = "";
//         for (int i = 0; i < n; i++) 
//         {
//             if (str[i] == ' ') {
//                 word = "";
//                 continue;
//             }
//             if (str[i] == ' ' && i==(n-1)) {
//                 return word.length();
//                 continue;
//             }
//             else {
//                 word += str[i];
//             }
//         }
//         return word.size();
//     }
// };

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                counting = true;
                length++;
            }
            else if (counting==true) {
                break;
            }
        }
        
        return length;
    }
};