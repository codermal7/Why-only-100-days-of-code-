// BRUTE
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n=nums.size(),maxi=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 maxi=max(maxi,(nums[i]-1)*(nums[j]-1));
//             }            
//         }
//         return maxi;
//     }
// };

// BETTER USING PQ
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n=nums.size(),maxi=0;
//         priority_queue<int> maxHeap;
//         for(auto it:nums)
//         {
//             maxHeap.push(it);
//         }
//         int a=maxHeap.top();
//         maxHeap.pop();
//         int b=maxHeap.top();
//         int c=(a-1)*(b-1);
//         return c;
//     }
// };

// OPTIMAL
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n1=INT_MIN,n2=INT_MIN;
        for(auto it:nums)
        {
            if(it>n1)
            {
                n2=n1;
                n1=it;
            }
            else if(it>n2)
            n2=it;
        }
        return (n1-1)*(n2-1);
    }
};