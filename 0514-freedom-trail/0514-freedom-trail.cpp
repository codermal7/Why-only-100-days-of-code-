class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        unordered_map<char, vector<int>> characterIndices;
        for (int i = 0; i < ring.length(); i++) {
            char ch = ring[i];
            characterIndices[ch].push_back(i);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, 0, 0});
        unordered_set<string> seen;
        int totalSteps = 0;
        while (!heap.empty()) {
            vector<int> state = heap.top();
            heap.pop();
            totalSteps = state[0];
            int ringIndex = state[1];
            int keyIndex = state[2];
            if (keyIndex == keyLen) {
                break;
            }
            string currentState = to_string(ringIndex) + "-" + to_string(keyIndex);
            if (seen.count(currentState)) {
                continue;
            }

            seen.insert(currentState);
            for (int nextIndex : characterIndices[key[keyIndex]]) {
                heap.push({totalSteps + countSteps(ringIndex, nextIndex, ringLen), 
                            nextIndex, keyIndex + 1});
            }
        }
        return totalSteps + keyLen;
    }

private:
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
};