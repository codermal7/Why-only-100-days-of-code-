class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for (int i = 1; i <= n*n; i++)
        {
            mp[i] = 0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[arr[i][j]]++;
            }
        }

        for(auto it:mp)
        {
            if(it.second>1)
            ans.push_back(it.first);
        }
        for(auto it:mp)
        {
            if(it.second<1)
            ans.push_back(it.first);
        }
        return ans;
    }
};