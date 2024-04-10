// class Solution {
// public:
//     bool checkValidString(string s) {
//         stack<char> st;
//         for(char ch:s)
//         {
//             if(ch=='(')
//             st.push(ch);
//             else if(ch==')' && st.empty())
//             return false;
//             else if(ch==')')
//             st.pop();
//         }
//         return st.empty();
//     }
// };
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char ch : s) {
            low += (ch == '(') ? 1 : -1;
            high += (ch != ')') ? 1 : -1;
            if (high < 0) return false;
            low = max(low, 0);
        }
        return low == 0;
    }
};