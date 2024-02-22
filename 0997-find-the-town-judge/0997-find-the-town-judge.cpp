// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         unordered_map<int,int>mp;
//         for (auto it : trust) {
//             mp[it[0]]--;
//             mp[it[1]]++;
//         }
//         for (int i = 1; i <= n; ++i) {
//             if (mp[i] == n - 1)
//                 return i;
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==1)
        return trust[0][1];
        vector<int> ansvect(n + 1, 0); 
        for (auto it : trust) {
            ansvect[it[0]]--; 
            ansvect[it[1]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (ansvect[i] == n - 1)
                return i;
        }
        return -1;
    }
};