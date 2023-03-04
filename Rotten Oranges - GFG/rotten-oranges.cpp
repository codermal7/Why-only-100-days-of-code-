//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        queue <pair < pair <int,int>,int > > q;
        int vis[n][m];
        int cnt=0,cnt_fr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)
                {
                    cnt_fr++;
                }
            }
        }
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int tm=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(auto d : dir) 
            {
                int drow = r + d.first;
                int dcol = c + d.second;
                if(drow>=0 && drow<n && dcol>=0 && dcol<m 
                && grid[drow][dcol]==1 && vis[drow][dcol]==0)
                {
                    vis[drow][dcol]=2;
                    q.push({{drow,dcol},t+1});
                    cnt++;
                }                
            }
        }
        if(cnt!=cnt_fr)
        return -1;
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends