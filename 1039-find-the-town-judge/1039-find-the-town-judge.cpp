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
// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<int> ansvect(n + 1, 0); 
//         for (auto it : trust) {
//             ansvect[it[0]]--; 
//             ansvect[it[1]]++;
//         }
//         for (int i = 1; i <= n; ++i) {
//             if (ansvect[i] == n - 1)
//                 return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {  
	 // Arrays to track trust given and received
        vector<int> trusting(n + 1, 0);   
        vector<int> trusted(n + 1, 0);     
        for (auto i : trust) {                    // Count trust relationships
            trusting[i[0]]++;                    // Increment trust given
            trusted[i[1]]++;                    // Increment trust received
        }
        int ans = -1;                            // Initialize result
                       
        for (int i = 1; i <= n; i++)           // Find the person trusted by everyone else
            if (trusting[i] == 0 && trusted[i] == n - 1){ 
                ans = i;             // Update result
            }
        return ans;                // Return judge's index or -1 if not found
    }
};