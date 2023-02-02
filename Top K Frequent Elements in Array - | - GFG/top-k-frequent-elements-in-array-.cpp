//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        map<int,int> mpp;int N=nums.size();
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


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends