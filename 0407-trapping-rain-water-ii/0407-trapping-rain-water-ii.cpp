class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        if(i < m && j<n && i>=0 && j>= 0){
            return true;
        }
        return false;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int totalwatervolume = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>boundary;
        //first col //last col
        for(int i=0; i<m; i++){
            boundary.push({heightMap[i][0], {i, 0}});
            visited[i][0] = 1;
            boundary.push({heightMap[i][n-1], {i, n-1}});
            visited[i][n-1] = 1;
        }
        //first row & last row
        for(int j=0; j<n; j++){
            boundary.push({heightMap[0][j], {0, j}});
            visited[0][j] = 1;
            boundary.push({heightMap[m-1][j], {m-1, j}});
            visited[m-1][j] = 1;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while(!boundary.empty()){
            auto top = boundary.top();
            boundary.pop();

            int row = top.second.first;
            int col = top.second.second;
            int currheight = top.first;
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(isvalid(nrow, ncol, m, n) && !visited[nrow][ncol]){
                    int nheight = heightMap[nrow][ncol];
                    if(nheight < currheight){
                        totalwatervolume += (currheight - nheight);
                    }

                    boundary.push({max(nheight, currheight), {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                }
            }

        }
        return totalwatervolume;
    }
};