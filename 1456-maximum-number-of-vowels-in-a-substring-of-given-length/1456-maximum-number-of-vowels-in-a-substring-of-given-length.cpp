class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size(),ans=0,cur=0;
        unordered_map<char,int>m;
        m['a']++,m['e']++,m['i']++,m['o']++,m['u']++;
        for(int i=0;i<n;i++){
            if(i<k){
                cur+=m.count(s[i]);
            }
            else{
                cur+=m.count(s[i])-m.count(s[i-k]);
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};