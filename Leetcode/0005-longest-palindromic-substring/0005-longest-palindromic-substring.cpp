class Solution {
public:
    string longestPalindrome(string s) 
    {
        int maxStart = 0;
        int maxLength = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            checkPalindrome(s, i, i, maxStart, maxLength);
            checkPalindrome(s, i, i+1, maxStart, maxLength);
        }
        
        return s.substr(maxStart, maxLength);      
    }
    
    void checkPalindrome(string s, int left, int right, int& maxStart, int& maxLength)
    {
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        
        int start = left + 1;
        int length = right - left - 1;
        
        if(maxLength < length)
        {
            maxStart = start;
            maxLength = length;
        }
    }
};