class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        while(n>0)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        if(sum==1)
            return true;
        else if(sum==4) // This is added to handle non-happy numbers
            return false;
        else
            return isHappy(sum);
    }
};