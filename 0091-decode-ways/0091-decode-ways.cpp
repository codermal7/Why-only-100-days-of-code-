class Solution {
public:
  int numDecodings(string s) {
    if(s[0] == '0') return 0;
    if(s.size() == 1) return 1;
    int rez = 0;
    
    if(s.size() == 2){
      if(s[1] != '0') rez++;
      if((s[0]-'0')*10 + (s[1]-'0') < 27) rez++;
      return rez;
    }
    
    int i=0;
    for(;i < s.size(), s[i] == '0'; i++);
    
    vector <int> ans(s.size());
    ans[0]++;
    if(s[1] == '0' && s[0] > '2') return 0;
    if((s[0]-'0')*10 + (s[1]-'0') < 27 && s[1] != '0') ans[1] = 2;
    else ans[1] = 1;
    
    for(int i = 2;i < s.size(); i++){                       
      if(s[i] == '0')
        if( s[i-1] > '2' || s[i-1] == '0') return 0;
        else {ans[i]=ans[i-2];continue;}
      if(s[i-1] == '0') {ans[i]=ans[i-1];continue;}
      if((s[i-1]-'0')*10 + (s[i]-'0') < 27) ans[i]=ans[i-2]+ans[i-1];
      else ans[i]=ans[i-1];
    }
    
    return ans[s.size()-1];
  }
};