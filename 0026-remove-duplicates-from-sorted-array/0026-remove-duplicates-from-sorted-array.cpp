class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        set<int> set1;
        for (const int &i: nums) 
        {
            set1.insert(i);
        }int a=0;
        for (const int &i: set1) 
        {
            nums[a]=i;
            a++;
        }
        return set1.size();
    }
};