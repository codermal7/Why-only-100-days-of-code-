class Solution {
public:
    vector<vector<int>>ans;
    void help(int i,int t,vector<int>&c,vector<int>&vec){
        if(t==0){
            ans.push_back(vec);
            return;
        }
        if(t<0){
            return;
        }
        if(i==c.size()){
            return;
        }
        help(i+1,t,c,vec); // if ith ele is ignored
        vec.push_back(c[i]);
        help(i,t-c[i],c,vec);// if ith ele is not ignored
        vec.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>vec;
        help(0,t,c,vec);
        return ans;
    }
};