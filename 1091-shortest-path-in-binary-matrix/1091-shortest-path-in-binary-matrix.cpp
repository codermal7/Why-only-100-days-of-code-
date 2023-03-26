class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g, int steps = 0) {
  queue<pair<int, int>> q;
  q.push({ 0, 0 });
  while (!q.empty()) {
    ++steps;
    queue<pair<int, int>> q1;
    while (!q.empty()) {
      auto c = q.front();
      q.pop();
      if (exchange(g[c.first][c.second], 1) == 1) continue;
      if (c.first == g.size() - 1 && c.second == g.size() - 1) return steps;
      for (auto i = c.first - 1; i <= c.first + 1; ++i)
        for (auto j = c.second - 1; j <= c.second + 1; ++j)
          if (i != c.first || j != c.second) {
            if (i >= 0 && j >= 0 && i < g.size() && j < g.size() && !g[i][j]) {
              q1.push({ i, j });
            }
          }
    }
    swap(q, q1);
  }
  return -1;
}
};