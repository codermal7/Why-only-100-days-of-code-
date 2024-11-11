class Solution {
public:
    int find(vector<int>&prime,int num)
    {
        int l=-1;
        int r=prime.size();

        while(r>l+1)
        {
            int mid=(l+r)/2;
            if(prime[mid]<num)
            l=mid;
            else
            r=mid;
        }

        if(r==prime.size())
        return -1;

        return prime[r];
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;

        for(int i=2; i<=1000; i++)
        {
            bool b=1;
            for(int j=2; j*j<=i; j++)
            {
                if(i%j==0)
                {
                    b=0;
                    break;
                }
            }
            if(b)
            prime.push_back(i);
        }
        
        int n=nums.size();
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]>=nums[i+1])
            {
                int t=nums[i]-(nums[i+1]-1);
                int num=find(prime,t);
                if(num==-1)
                return 0;
                nums[i]=nums[i]-num;
                if(nums[i]<=0)
                return 0;
            }
        }
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1]<=nums[i])
            return 0;
        }
        return 1;
    }
};