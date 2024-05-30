class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> m;

        int prefix = 0;
        m[0] = make_pair(1, -1);
        int c = 0;
        for (int i = 0; i < arr.size(); i++) {
            prefix ^= arr[i];

            if (i != 0 && m.find(prefix) != m.end()) {
                c += ((i - 1) * m[prefix].first - m[prefix].second);
            }

            m[prefix].first++;
            m[prefix].second += i;
        }

        return c;
    }
};