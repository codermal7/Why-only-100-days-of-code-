class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')' || s[0]==']' || s[0]=='}')
        return false;
        stack<char> st; int i=1;
        st.push(s[0]);
        while(!st.empty() || i<s.size())
        {
            if((s[i]=='(' || s[i]=='{' || s[i]=='[') && (i<s.size()))
            {
                st.push(s[i]);
            }
            else if((s[i]==')' || s[i]==']' || s[i]=='}') && (!st.empty()))
            {
                char ch=st.top();
                if((ch=='(' && s[i]==')') || (ch=='[' && s[i]==']') || 
                (ch=='{' && s[i]=='}'))
                st.pop();
                else
                return false;
            }
            else{
                return false;
            }
            i++;
        }
        return true;
    }
};