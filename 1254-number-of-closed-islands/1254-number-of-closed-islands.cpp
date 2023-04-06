class Solution {
public:
    
    int f=0;
    void helper(int i,int j,int n,int c,int oldc,vector<vector<int>>& grid)
    {
        if(i<0 || i>=n || j<0 || j>=c || grid[i][j]!=oldc)
            return ;
        if(i==0 || i==n-1 || j==0 || j==c-1)
            f=1;
        grid[i][j]=-1;
        helper(i+1,j,n,c,oldc,grid);
        helper(i-1,j,n,c,oldc,grid);
        helper(i,j+1,n,c,oldc,grid);
        helper(i,j-1,n,c,oldc,grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                f=0;
                if(grid[i][j]==0)
                {
                    helper(i,j,grid.size(),grid[i].size(),grid[i][j],grid);
                    if(f==0)
                        c+=1;
                }
            }
        }
        return c;
    }
};