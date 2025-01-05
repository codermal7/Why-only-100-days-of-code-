class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int m = s.size();
        vector<int> diff(m, 0);
        for(int i=0; i<n; i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            if(direction){
                diff[start] += 1;
                if(end+1 < m) diff[end+1] -= 1;
            }else{
                diff[start] -= 1;
                if(end+1 < m) diff[end+1] += 1;
            }
        }
        for(int i=1; i<m; i++) diff[i] += diff[i-1];
        for(int i=0; i<m; i++){
            char ch = s[i];
            int newIdx = ch - 'a';
            newIdx = (newIdx + diff[i]) % 26;  
            newIdx = (newIdx + 26) % 26;      
            s[i] = (char)('a' + newIdx);
        }
        return s;
    }
};