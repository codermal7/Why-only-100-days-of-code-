// #include <bits/stdc++.h>
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n=nums.size(),c=1;vector<int> ans;vector<int> miss;
//         sort(nums.begin(),nums.end());bool check;
//         while(c<=n)
//         {
//             check=false;
//             for(int i=0;i<n;i++)
//             {
//                 if(c==nums[i])
//                 {
//                     check=true;
//                     break;
//                 }
//             }
//             if(check==false)
//             miss.push_back(c);
//             c++;
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]==nums[j])
//                 {
//                     ans.push_back(nums[i]);
//                 }
//             }
//         }
//         ans.insert(ans.end(), miss.begin(), miss.end());
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        int duplicate = -1, missing = -1;

        for (int num : nums) {
            if (numSet.find(num) != numSet.end()) {
                duplicate = num;
            } else {
                numSet.insert(num);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (numSet.find(i) == numSet.end()) {
                missing = i;
                break;
            }
        }
        return {duplicate, missing};
    }
};


