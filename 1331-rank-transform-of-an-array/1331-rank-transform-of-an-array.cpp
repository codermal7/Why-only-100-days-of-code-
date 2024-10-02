class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank = 1;
        map<int,vector<int>> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        for (auto& it : mp) {
            for (int i : it.second) {
                arr[i] = rank;
            }
            rank++;
        }
        return arr;
    }
};