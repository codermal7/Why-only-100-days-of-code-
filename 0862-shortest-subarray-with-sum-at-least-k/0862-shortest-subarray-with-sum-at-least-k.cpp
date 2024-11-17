class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> vec(nums.size());
        int ans = INT_MAX;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            vec[i] = nums[i];
            if (i)
                vec[i] += vec[i - 1];
            if (vec[i] >= k)
                ans = min(ans, i + 1);
            while (!dq.empty() && vec[i] - vec[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && vec[dq.back()] >= vec[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};