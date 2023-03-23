class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();int lsum=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        cout<<sum<<endl;
        int rsum=sum;
        for(int i=0;i<n;i++)
        {
            rsum-=nums[i];
            cout<<"lsum "<<lsum<<" rsum "<<rsum<<endl;
            if(lsum==rsum)
                return i;
            lsum+=nums[i];
        }
        return -1;
    }
};