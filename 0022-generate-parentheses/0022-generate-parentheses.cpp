class Solution {
public:
    void helper(int n, int open, int close, string tmp, vector<string>&res)
    {
        if(open==n && close == n)
        {
            res.push_back(tmp);
        }
        if(open<n)
        {
            helper(n,open+1,close,tmp+'(',res);
        }
        if(close<open)
        {
            helper(n,open,close+1,tmp+')',res);
        }
    }
    vector<string> generateParenthesis(int n) {
        string tmp;
        vector<string>res;
        helper(n,0,0,tmp,res);
        return res;
    }
};