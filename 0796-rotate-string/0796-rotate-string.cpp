class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        int i=0;
        if(m!=n){
            return false;
        }
        while(i<n){
            if(s==goal){
                return true;
            }
            char a=s[0];
            for(int j=0;j<n-1;j++){
                s[j]=s[j+1];
            }
            s[n-1]=a;
            i++;
            
        }
        return false;
        
    }
};