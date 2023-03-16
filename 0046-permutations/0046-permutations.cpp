class Solution {
public:

    void _permute(vector<int>& nums, int i,vector<vector<int>>& ans, vector<int> &temp, vector<bool>& used){
        if(i==nums.size()) ans.push_back(temp);

        for(int j=0; j<nums.size(); j++){
            if(!used[j]){
                temp.push_back(nums[j]);
                used[j] = true;
                // Recursively generate permutations with the remaining elements
                _permute(nums, i + 1, ans, temp, used);
                // Backtrack: Mark the element as unused and remove it from the temp permutation
                used[j] = false;
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        _permute(nums, 0, ans, temp, used);

        return ans;

    }
};
