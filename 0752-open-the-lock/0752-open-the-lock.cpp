class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int time = 0;
        unordered_map<string, int> deadend, vis;
        for (auto s : deadends) {
            deadend[s]++;
        }

        queue<string> q;
        q.push("0000");

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto curr = q.front();
                q.pop();

                if (curr == target)
                    return time;
                if (deadend[curr] > 0 || vis[curr] > 0)
                    continue;
                vis[curr]++;
                for (int i = 0; i < 4; i++) {
                    string ori = curr;
                    curr[i] = (ori[i] == '9') ? '0' : ori[i] + 1;
                    q.push(curr);
                    curr[i] = (ori[i] == '0') ? '9' : ori[i] - 1;
                    q.push(curr);
                    curr = ori;
                }
            }
            time++;
        }
        return -1;
    }
};