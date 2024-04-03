class Solution {
public:
    int partitionString(string s) {
        int freq[27]= {0} ;
        int ans= 0 ;
        for(int i=0; i<s.size(); i++){
            if(freq[s[i] - 96] > 0){
                ans++ ;
                for(int j=0; j<27; j++) freq[j]= 0 ;
            }
            freq[s[i] - 96]++ ;
        }
        ans++ ;
        return ans ;
    }
};