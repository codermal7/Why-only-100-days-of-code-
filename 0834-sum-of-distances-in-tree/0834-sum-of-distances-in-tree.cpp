class Solution {
public:
	int n ;
	vector<vector<int>> adj;
	vector<int> cnt;
	vector<int> ans;
	int rec2(int node , int par) {
		int ans = 0 ;
		for (auto it : adj[node]) {
			if (it != par) {
				ans += (1 + rec2(it, node));
			}
		}
		cnt[node] = ans + 1;
		return ans ;
	}
	int rec(int node , int par, int prev) {
		int ans = 0 ;
		for (auto it : adj[node]) {
			if (it != par) {
				ans += ( prev + rec(it, node, prev + 1));
			}
		}
		return ans ;
	}
	void solve(int node , int par) {
		for (auto it : adj[node]) {
			if (it != par) {
            	ans[it] = ans[node] - cnt[it] + n - cnt[it];
				solve(it, node);
			}
		}
	}
	vector<int> sumOfDistancesInTree(int nn, vector<vector<int>>& edges) {
        n = nn;
		adj.resize(n);
		cnt.resize(n);
		ans.resize(n);
		for (auto it : edges) {
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
		}
		rec2(0, -1);
		ans[0] = rec(0, -1, 1);
		solve(0, -1);
		return ans ;
	}
};