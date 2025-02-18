class Solution {
public:
    string smallestNumber(string s) {
        string sol; stack<int> st;
        int len = s.length();
        
        for (int i = 0; i <= len; ++i) {
            st.push(i + 1);
            if (i == len || s[i] == 'I') {
                while (!st.empty()) {
                    sol += to_string(st.top());
                    st.pop();
                }
            }
        }
        return sol;
    }
};