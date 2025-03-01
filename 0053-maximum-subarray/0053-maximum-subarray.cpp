class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(); int sum=0, maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            sum=0;
        }
        return maxi;

        // My code for also printing the maximum subarray sum
        /*
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        int start = 0, end = 0, s = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum > maxSum) { 
                maxSum = sum;
                start = s;
                end = i;
            }

            if (sum < 0) {
                sum = 0;
                s = i + 1;
            }
        }

        cout << "Maximum Subarray Sum: ";
        for (int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return maxSum;
        */
    }
};