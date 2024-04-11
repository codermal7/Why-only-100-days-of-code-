class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st; 
        int n=num.size();
        if(num.size()==1 && k>=1) return "0";
        if(num.size()<=k) return "0";

        for(int i=0;i<n;i++){
            if(st.size()==0){
                st.push(num[i]);
            }
            else{
                if(k){
                    while(k!=0 && !st.empty() && st.top() > num[i]){
                        st.pop();k--;
                    }
                }
                st.push(num[i]);
            }
        }
        while(k--) st.pop();
        string ans="";
        while(!st.empty()) {
            ans.push_back(st.top());st.pop();
        }
        char c=ans.back();
        while(ans.size()>0 && c=='0' && ans.back()==c) ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans.size()==0) ans.push_back('0');
        return ans;
    }
};