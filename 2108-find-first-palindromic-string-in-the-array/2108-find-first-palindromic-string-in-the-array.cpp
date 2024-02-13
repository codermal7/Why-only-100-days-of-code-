class Solution {
public:
    bool streverse(string s)
    {
        string m=s;
        reverse(s.begin(),s.end());
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