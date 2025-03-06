class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        int n=arr.size(),a,b;
        unordered_map<int,int> mp;
        
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
            a=it.first;
        }
        for(auto it:mp)
        {
            if(it.second<1)
            b=it.first;
        }
        return {a,b};
    }
};