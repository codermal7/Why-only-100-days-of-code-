class Solution {
public:
    void setrowzero(vector<vector<int>>&  matrix, int r, int c, int i)
    {
        for(int j=0;j<c;j++)
        {
            if(matrix[i][j]!=0)
            matrix[i][j]=-83748348;
        }
    }
    void setcolzero(vector<vector<int>>& matrix, int r, int c, int j)
    {
        for(int i=0;i<r;i++)
        {
            if(matrix[i][j]!=0)
            matrix[i][j]=-83748348;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    setrowzero(matrix,r,c,i);
                    setcolzero(matrix,r,c,j);
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==-83748348)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};