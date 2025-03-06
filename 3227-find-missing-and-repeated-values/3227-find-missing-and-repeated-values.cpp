class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        int n = arr.size();
        long long sum = 0, sum_sq = 0;
        for (auto& row : arr) {
            for (int num : row) {
                sum += num;
                sum_sq += (long long)num * num;
            }
        }
        long long n_sq = (long long)n * n;
        long long S = n_sq * (n_sq + 1) / 2;
        long long S_sq = n_sq * (n_sq + 1) * (2 * n_sq + 1) / 6;
        long long delta_sum = sum - S;
        long long delta_sq_sum = sum_sq - S_sq;
        long long a_plus_b = delta_sq_sum / delta_sum;
        int a = (delta_sum + a_plus_b) / 2;
        int b = (a_plus_b - delta_sum) / 2;
        return {a, b};
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();