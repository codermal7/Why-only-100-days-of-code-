class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();int m=image[0].size();
        queue <pair<int,int>> q;
        vector<vector<int>> vis=image;
        int cnt=0,cnt_fr=0;
        q.push({sr,sc});
        vis[sr][sc]=newColor;
        vector<vector<int>> touch(n, vector<int>(m, 0));
        touch[sr][sc]=1;
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int tm=0;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            int x=image[r][c];
            q.pop();
            for(auto d : dir) 
            {
                int drow = r + d.first;
                int dcol = c + d.second;
                if(drow>=0 && drow<n && dcol>=0 && dcol<m 
                && image[drow][dcol]==x &&  touch[drow][dcol]==0)
                {
                    touch[drow][dcol]=1;
                    vis[drow][dcol]=newColor;
                    q.push({drow,dcol});
                }                
            }
        }
        return vis;
    }
};