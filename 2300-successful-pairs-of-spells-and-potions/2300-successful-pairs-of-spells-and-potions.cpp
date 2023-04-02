class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        // suppport variables
        int len = spells.size(), maxVal = *max_element(begin(spells), end(spells)) + 1, precomputed[maxVal];
        long long threshold;
        double spellVal;
        vector<int> res(len);
        // preparing precomputed
        fill(precomputed, precomputed + maxVal, -1);
        // preparing potions for the BS
        sort(begin(potions), end(potions));
        for (int i = 0, tmpSpell; i < len; i++) {
            tmpSpell = spellVal = spells[i];
            // checking if we already had computed a result for that value
            if (precomputed[tmpSpell] != -1) {
                res[i] = precomputed[tmpSpell];
                continue;
            }
            // computing the threshold value we need to get in potions, if we did not see if before
            threshold = (success + spellVal - 1) / spellVal;
            // adding to res how many such values are in potions through BS
            res[i] = precomputed[tmpSpell] = end(potions) - lower_bound(begin(potions), end(potions), threshold);
        }
        return res;
    }
};