class Solution {
public:
    int maxScore(string s) {
        int maxi=0;
        for(int i=0;i<s.size()-1;i++)
        {
            int c=0;
            for(int j=0;j<=i;j++)
            {
                if(s[j]=='0')
                c++;
            }
            for(int j=i+1;j<s.size();j++)
            {
                if(s[j]=='1')
                c++;
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};