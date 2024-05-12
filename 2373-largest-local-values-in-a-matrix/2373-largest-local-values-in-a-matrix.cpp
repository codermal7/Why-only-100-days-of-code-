class Solution {
public:
    int findMax(int x,int y,vector<vector<int>>&grid){
         int max=INT_MIN;
         for(int i=x;i<x+3;i++){
             for(int j=y;j<y+3;j++){
                 if(max<grid[i][j])
                   max=grid[i][j];
             }
         }
         return max;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j]=findMax(i,j,grid);
            }
        }
        return ans;
    }
};