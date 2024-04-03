class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;int N=nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<N;i++)
        {
            mpp[nums[i]]++;
        }
        vector<int> V;
        for(auto i:mpp)
        {
            pq.push({i.second, i.first});
        }
        for(int i=0;i<k;i++)
        {
            V.push_back(pq.top().second);
            pq.pop();
        }
        return V;
    }
};