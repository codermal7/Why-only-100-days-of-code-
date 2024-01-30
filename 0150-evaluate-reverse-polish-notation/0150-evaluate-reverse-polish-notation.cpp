class Solution {
public:
    int evalRPN(vector<string>& t) {
        int n = t.size();
        stack<int> s;
        int fir;
        int sec;
        //int ans;

        for(int i=0; i<n; i++){
            int ans;
            if(t[i]=="+" || t[i]=="-" || t[i]=="*" || t[i]=="/"){
                sec = s.top();
                s.pop();
                fir = s.top();
                s.pop();
                if(t[i]=="+") ans = fir + sec;
                else if(t[i]=="-") ans = fir - sec;
                else if(t[i]=="*") ans = fir * sec;
                else ans = fir / sec;
                s.push(ans);
            }

            else{
                s.push(std::stoi(t[i]));
            }
        }
        return s.top();

    }
};