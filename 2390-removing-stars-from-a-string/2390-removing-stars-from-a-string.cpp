class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*') st.pop();
            else st.push(s[i]);
        }
        int  count = 0;
        string ans  = "";
        while(!st.empty()){
            ans+=  st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};