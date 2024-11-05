class Solution {
public:
    int minChanges(string s) {
       int result=0, n=s.size()-1;
       for(int i=0;i<n;i+=2){
            if(s[i]!=s[i+1]){
                result++;
            }
       }
       return result;
    }
};