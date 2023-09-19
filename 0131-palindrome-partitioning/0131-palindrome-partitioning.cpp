class Solution {
public:
    bool isPalindrome(string &s)
    {
        int temp=s.length();
        if(!temp) return false;
        if(temp==1) return true;
        else{
            for (int i = 0,j= temp-1; i <j; i++,j--) if(s[i]!=s[j]) return false;
            return true;
        }
    }
    void backtrack(string s,vector<string> &sub, vector<vector<string>> &res)
    {
        if(s.empty()) return;
        if(s.length()==1) 
        {
            sub.push_back(s);
            res.push_back(sub);
            sub.pop_back();
            return;
        }

        for (int i = 1; i <=s.length(); i++)
        {
            string str=s.substr(0,i);
            if(isPalindrome(str)) 
            {
                sub.push_back(str);
                if(i==s.length())
                {
                    res.push_back(sub);
                    sub.pop_back();
                    return;
                }
                backtrack(s.substr(i),sub, res);
                sub.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub;
        backtrack(s,sub,res);
        return res;
    }
};