class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        // 1
        // int n=nums1.size(), nn=nums2.size();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<nn;j++)
        //     {
        //         if(nums1[i]==nums2[j])
        //         return nums1[i];
        //     }
        // }
        // return -1;
        


        // 2
        // unordered_set<int> set1(nums1.begin(), nums1.end());
        // for (int num : nums2) {
        //     if (set1.contains(num)) {
        //         return num;
        //     }
        // }
        // return -1;



        // 3
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j]) return nums1[i];
            if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return -1;
    }
};