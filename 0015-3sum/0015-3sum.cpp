class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> res;int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<n-2;i++)
    //     {
    //         if(i==0 ||(i>0 && nums[i]!=nums[i-1]))
    //         {
    //             int lo=i+1,hi=n-1,sum=0-nums[i];
    //             while(lo<hi)
    //             {
    //                 if(nums[lo]+nums[hi]==sum)
    //                 {
    //                     vector<int> trio={nums[i], nums[lo], nums[hi]};
    //                     res.push_back(trio);
    //                     while(lo<hi && nums[lo]==nums[lo+1])lo++;
    //                     while(lo<hi && nums[hi]==nums[hi-1])hi++;
    //                     lo++;hi--;
    //                 }
    //                 else if(nums[lo]+nums[hi]<sum)
    //                     lo++;
    //                 else
    //                     hi--;
    //             }
    //         }
    //     }
    //     return res;
    // }
    
    vector<vector<int> > res;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {

                int sum = nums[front] + nums[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1]) front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == triplet[2]) back--;
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;

        }

        return res;
    }
};