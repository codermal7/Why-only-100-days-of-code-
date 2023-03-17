class Solution {
    public boolean isPowerOfTwo(int n) 
    {
        for(int j=0;j<=31;j++)
        {
            if(Math.pow(2,j)==n)
                return true;
        }
        return false;        
    }
}