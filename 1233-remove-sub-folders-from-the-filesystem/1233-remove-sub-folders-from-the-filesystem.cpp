#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = [](){ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return 'c'; 
}();

class Solution {
public:
    static vector<string> removeSubfolders(vector<string>& vec) {
        sort(vec.begin(),vec.end());
        int n=vec.size();string pre=vec[0];
        vector<string> res={vec[0]};
        for(int i=1;i<n;i++){
            string str=vec[i];
            if(str.find(pre+'/')!=0){
                res.push_back(str);
                pre=str;
            }
        }
        return res;
    }
};