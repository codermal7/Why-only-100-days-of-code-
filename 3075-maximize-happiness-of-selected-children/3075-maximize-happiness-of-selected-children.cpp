class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(const auto& h: happiness)
            pq.push(h); 

        long long totalHappinessSum = 0;
        int turns = 0;

        for(int i = 0; i < k; i++) {
            totalHappinessSum += max(pq.top() - turns, 0);
            pq.pop();            
            turns++; 
        }
        return totalHappinessSum;
    }
};