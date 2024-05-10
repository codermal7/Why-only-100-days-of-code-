class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<double, double>>> pq;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i+1; j < arr.size(); j++) {
                double div =(double) arr[i] / arr[j];
                pq.push({div, {arr[i], arr[j]}});
            }
        }
        int r=pq.size()-k;
        while (r--) {
            pq.pop();
        }
        auto it = pq.top();
        vector<int> ans(2);
        ans[0] = it.second.first;
        ans[1] = it.second.second;
        return ans;
    }
};