class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;int rev=0;
        while(x>0)
        {   
            if(rev > INT_MAX/10 || rev < INT_MIN/10)
            {
                return 0 ;
            }         
            rev=rev*10+(x%10);
            x/=10;
        }
        if(rev==n)
            return true;
        return false;
    }
};