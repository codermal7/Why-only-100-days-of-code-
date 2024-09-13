class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> vect(n + 1, 0);

        for (int i = 0; i < n; i++) {
            vect[i + 1] = vect[i] ^ arr[i];
        }

        vector<int> result;
        for (const auto& q : queries) {
            result.push_back(vect[q[1] + 1] ^ vect[q[0]]);
        }
        return result;
    }
};