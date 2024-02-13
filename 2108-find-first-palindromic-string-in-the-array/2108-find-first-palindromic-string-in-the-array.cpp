class Solution {
public:
    bool streverse(string s)
    {
        string m=s;int len=s.length();
        int l=0,h=len-1;
        while(l<=h)
        {
            swap(s[l++],s[h--]);
        }
        // reverse(s.begin(),s.end());
        if(m==s)
            return true;
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            if(streverse(words[i]))
            return words[i];
        }
        return "";
    }
};