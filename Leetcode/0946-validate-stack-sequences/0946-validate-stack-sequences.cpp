class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack<int> st;

        while(i < pushed.size() && j < popped.size()){
            if(st.empty()){
                st.push(pushed[i]);
                i++;
                continue;
            }

            if(popped[j] == st.top()){
                st.pop();
                j++;
            }else{
                st.push(pushed[i]);
                i++;
            }
        }
        while(j < popped.size()){
            if(popped[j] == st.top()){
                st.pop();
                j++;
            }else{
                break;
            }
        }

        return st.empty();
    }
};