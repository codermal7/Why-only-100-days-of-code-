// class Solution {
// public:
//     vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
//         int len = spells.size(), maxVal = *max_element(begin(spells), end(spells)) + 1, precomputed[maxVal];
//         long long threshold;
//         double spellVal;
//         vector<int> res(len);
//         fill(precomputed, precomputed + maxVal, -1);
//         sort(begin(potions), end(potions));
//         for (int i = 0, tmpSpell; i < len; i++) {
//             tmpSpell = spellVal = spells[i];
//             if (precomputed[tmpSpell] != -1) {
//                 res[i] = precomputed[tmpSpell];
//                 continue;
//             }
//             threshold = (success + spellVal - 1) / spellVal;
//             res[i] = precomputed[tmpSpell] = end(potions) - lower_bound(begin(potions), end(potions), threshold);
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int len = spells.size(), maxVal = *max_element(begin(spells), end(spells)) + 1;
        long long threshold;
        double spellVal;
        vector<int> res(len);
        vector<int> precomputed(maxVal, -1);
        sort(begin(potions), end(potions));
        
        for (int i = 0; i < len; ++i) {
            int tmpSpell = spells[i];
            if (precomputed[tmpSpell] != -1) {
                res[i] = precomputed[tmpSpell];
            } else {
                spellVal = static_cast<double>(tmpSpell);
                threshold = (success + spellVal - 1) / spellVal;
                res[i] = precomputed[tmpSpell] = end(potions) - lower_bound(begin(potions), end(potions), threshold);
            }
        }
        
        return res;
    }
};