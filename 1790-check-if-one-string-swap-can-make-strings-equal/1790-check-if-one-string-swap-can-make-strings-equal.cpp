class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int x=-1,y=-1;

        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(x==-1)x=i;
                else if(y==-1)y=i;
                else break;
            }
        }

        if(x!=-1 && y!=-1)swap(s1[x],s1[y]);

        return s1==s2;
    }
};