class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        int n = arr.size();
        long long tN = n * n;
        long long eS = (long long)tN * (tN + 1) / 2;
        long long eSqS = (long long)tN * (tN + 1) * (2 * tN + 1) / 6;

        long long aS = 0, aSqS = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int v = arr[i][j];
                aS += v;
                aSqS += (long long)v * v;
            }
        }
        
        long long d = aS - eS;
        long long s_ab = (aSqS - eSqS) / d;

        int a = (int)((d + s_ab) / 2);
        int b = (int)(s_ab - a);

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