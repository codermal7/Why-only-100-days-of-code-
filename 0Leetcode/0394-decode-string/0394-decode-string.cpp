class Solution {
public:
    string decodeString(string s) {
        char buf[100001];
        bzero(buf, sizeof(buf));
        stack<pair<int,int>> st{};  // k, offset in buffer
        int pos{}, rep{};
        for (int i{}; i < s.length(); i++) {
            char c{s[i]};
            if (c == '[') {
                st.push({rep, pos});
                rep = 0;
            } else if (c == ']') {
                auto [k, base] = st.top();
                st.pop();
                int len = pos - base;
                for (int j{}; j < k-1; j++) {
                    strncpy(buf + pos, buf + base, len);
                    pos += len;
                }
            } else if (c >= '0' && c <= '9') {
                rep = (10 * rep) + (c - '0');
            } else {
                buf[pos++] = c;
            }
        }
        return string(buf);
    }
};