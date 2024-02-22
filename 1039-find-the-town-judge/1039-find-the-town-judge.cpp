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
// }

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    using int2=pair<int, int>;
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int2> degArr(n);
        for(int i=0; i<n; i++)
            degArr[i]={i+1, 0};
        //Initialize once all, not 1 by 1
        unordered_map<int, int> deg(degArr.begin(), degArr.end());
        for (auto& e: trust){
            int a=e[0], b=e[1];
            if (deg.count(a)) deg.erase(a);//outdeg(a)>0
            if (deg.count(b)) deg[b]++; //Only consider outdeg(b)=0
        }
        for (auto& [i, d] : deg)
            if (d==n-1) return i;
        
        return -1;      
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();