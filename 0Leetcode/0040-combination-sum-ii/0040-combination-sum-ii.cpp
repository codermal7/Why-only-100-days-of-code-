class Solution {
public:
    void search(vector<vector<int>>& vec, vector<int>& lv, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            vec.push_back(lv);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            lv.push_back(candidates[i]);
            search(vec, lv, candidates, target-candidates[i], i+1);
            lv.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vec;
        vector<int> lv;
        search(vec, lv, candidates, target, 0);
        return vec;
    }
};