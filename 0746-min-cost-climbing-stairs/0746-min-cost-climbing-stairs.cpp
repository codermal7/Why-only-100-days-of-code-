// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int a=0,b,l,r;
//         int n=cost.size();
//         for(int i=1;i<n;i++)
//         {
//             l=a+abs(cost[i]-cost[i-1]);
//             r=INT_MAX;
//             if(i>1)
//             r=b+abs(cost[i]-cost[i-2]);
//             b=a;
//             a=min(l,r);
//         }
//         return a;
//     }
    
// };


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};