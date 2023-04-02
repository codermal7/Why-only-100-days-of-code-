class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int i=0; i<spells.size(); i++)
        {
            long long int z = success / (long long int)spells[i];
            if(spells[i] * z < success)
                z++;
            int y = lower_bound(potions.begin(), potions.end(), z) - potions.begin();
            ans.push_back(potions.size() - y);
        }
        return ans;
    }
};