class Solution {
public:
    int maxScore(string s) {
        int l=s.size();int maxi=0;
        for(int i=0;i<l-1;i++)
        {
            int c=0;
            for(int j=0;j<=i;j++)
            {
                if(s[j]=='0')
                c++;
            }
            for(int j=i+1;j<l;j++)
            {
                if(s[j]=='1')
                c++;
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};