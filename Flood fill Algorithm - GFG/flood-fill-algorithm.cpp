//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends