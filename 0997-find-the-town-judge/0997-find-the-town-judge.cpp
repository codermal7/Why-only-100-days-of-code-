#include <vector>
using namespace std;

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