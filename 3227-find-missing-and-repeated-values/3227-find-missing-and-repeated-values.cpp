class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        // int n=arr.size(),a,b;
        // unordered_map<int,int> mp;
        
        // for (int i = 1; i <= n*n; i++)
        // {
        //     mp[i] = 0;
        // }

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         mp[arr[i][j]]++;
        //     }
        // }

        // for(auto it:mp)
        // {
        //     if(it.second>1)
        //     a=it.first;
        // }
        // for(auto it:mp)
        // {
        //     if(it.second<1)
        //     b=it.first;
        // }
        // return {a,b};
        
        // Rough mathematical formula guessing.
        
        // n=4;
        // sum=(n*(n+1))/2;
        // 10;
        // 10-2=8;

        // n=9;
        // sum=(n*(n+1))/2;
        // 45;
        // 45-9=36;

        // const int n=arr.size(), n2=n*n;
        // vector<unsigned char> freq(n2+1, 0);
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         freq[arr[i][j]]++;
        //     }
        // }
        // int a=0, b=0;
        // for(int i=1; i<=n2; i++){
        //     if (freq[i]==2) a=i;
        //     else if (freq[i]==0) b=i;
        // }
        // return {a, b};

        int a = 0 , b = 0;
        int n = arr.size();
        int m = n * n;
        int totalSum = (m * (m+1))/2;
        int sum = 0;
        unordered_set<int> nums;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (nums.count(arr[i][j])) 
                a=arr[i][j];
                else{
                    nums.insert(arr[i][j]);
                    sum += arr[i][j];
                }
            }
        }
        b = totalSum - sum;
        return {a,b};
    }
};