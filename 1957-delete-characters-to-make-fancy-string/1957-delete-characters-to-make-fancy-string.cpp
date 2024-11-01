class Solution {
public:
    string makeFancyString(string s) {
        int curr = s[0],c = 0, n = s.size();
        string a = "";
        for(int i = 0;i<n;i++){
            if(s[i] == curr){
                c++;
            }
            else{
                c = 1;
                curr = s[i];
            }
            if(c<=2){
                a+= s[i];
            }
        }
        return a;
    }  
};