class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> bobDepth(n, 0);
        queue<pair<int, int>> bobQueue;
        bobQueue.push({bob, 1});
        while (!bobQueue.empty()) {
            auto [node, dep] = bobQueue.front(); 
            bobQueue.pop();
            bobDepth[node] = dep++;
            if (node == 0) break;  
            for (int neighbor : graph[node]) 
                if (bobDepth[neighbor] == 0) bobQueue.push({neighbor, dep});
        }

        vector<int> dist(n, INT_MAX);
        queue<int> bfsQueue;
        bfsQueue.push(0);
        while (!bfsQueue.empty()) {
            int node = bfsQueue.front();
            bfsQueue.pop();
            dist[node] = bobDepth[node];
            if (node == bob) break;  
            for (int neighbor : graph[node]) 
                if (bobDepth[node] == bobDepth[neighbor] + 1) {
                    bfsQueue.push(neighbor);
                    break;
                }
        }
        vector<int> visited(n, 0);
        queue<tuple<int, int, int>> aliceQueue;
        aliceQueue.push({0, 1, 0});
        int maxProfit = INT_MIN;
        
        while (!aliceQueue.empty()) {
            auto [node, depth, profit] = aliceQueue.front(); 
            aliceQueue.pop();
            if (dist[node] > depth) profit += amount[node];
            else if (dist[node] == depth) profit += amount[node] / 2;
            visited[node] = 1;
            if (graph[node].size() == 1 && node != 0) 
                maxProfit = max(maxProfit, profit);
            else {
                for (int neighbor : graph[node]) 
                    if (!visited[neighbor]) 
                        aliceQueue.push({neighbor, depth + 1, profit});
            }
        }
        return maxProfit;
    }
};
