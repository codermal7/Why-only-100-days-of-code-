class Solution {
public:
    void subsequence(vector<int>& arr, int index,int n,vector<vector<int>>& ans, vector<int>& temp)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }
    
        // Not included
        subsequence(arr, index+1, n,ans, temp) ;
        // Included
        temp.push_back(arr[index]);
        subsequence (arr, index+1, n, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        subsequence(nums,0,nums.size(),ans,temp);
        return ans;
    }
};