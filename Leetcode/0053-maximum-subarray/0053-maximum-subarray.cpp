class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size(),maxi=INT_MIN,sum=0;
        for(int i=0;i<n;i++)
        {   
            sum+=arr[i];
            maxi=max(maxi,sum);
            if(sum<0)
            sum=0;
        }
        return maxi;
    }
};