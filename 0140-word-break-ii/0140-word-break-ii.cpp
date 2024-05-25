class Solution {
public:
    void solve(string s,vector<string>& wordDict,int i,unordered_set<string>st,vector<string>&ans,vector<string>temp)
    {
        if(i==s.length())
        {
            string str="";
            if(temp.size()>0)
            {
                for(int i=0;i<temp.size();i++)
                {
                    str+=temp[i];
                    if(i<temp.size()-1)
                        str+=" ";
                }
                ans.push_back(str);
            }
            return;
        }
        string str="";
        for(int j=i;j<s.length();j++)
        {
            str+=s[j];
            if(st.count(str))
            {
                temp.push_back(str);
                solve(s,wordDict,j+1,st,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<string>ans,temp;
        solve(s,wordDict,0,st,ans,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};