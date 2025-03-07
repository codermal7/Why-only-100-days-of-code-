class Solution {
public:
    // bool isPrime(int n)
    // {
    //     if (n <= 1) {
    //     return false;
    //     }
    //     if (n <= 3) {
    //         return true;
    //     }
    //     if (n % 2 == 0 || n % 3 == 0) {
    //         return false;
    //     }
    //     for (int i = 5; i * i <= n; i += 6) {
    //         if (n % i == 0 || n % (i + 2) == 0) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    vector<int> closestPrimes(int l, int r) {
        // vector<int> ans;
        // for(int i=l;i<=r;i++)
        // {
        //     if(ans.size()==2)
        //     break;
        //     if(isPrime(i))
        //     ans.push_back(i);
        // }
        // if(!ans.empty() && ans.size()==2)
        // return ans;

        // return {-1,-1};

        if (r < 2)
        return {-1, -1};
        
        int mini = INT_MAX;
        vector<bool> primeArr(r + 1, 1);

        primeArr[0] = primeArr[1] = false;
        for (int i = 2; i * i <= r; i++){
            if (primeArr[i]){
                for (int j = i * i; j <= r; j+= i){
                    primeArr[j] = false;
                }
            }
        }

        vector<int> primee;
        for (int i = l; i <= r; i++){
            if(primeArr[i])
                primee.push_back(i);
        }

        if (primee.size() < 2)
        return {-1, -1};

        vector<int> ans;

        for (size_t i = 1; i < primee.size(); i++){
            int diff = primee[i] - primee[i - 1];
            if (diff < mini){
                mini = diff;
                ans = {primee[i - 1], primee[i]};
            }
        }
        return ans;
    }
};