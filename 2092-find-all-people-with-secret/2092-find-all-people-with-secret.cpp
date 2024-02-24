class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, 
    int firstPerson) 
    {
        set<int> ans = {0, firstPerson};
        
        vector<vector<pair<int, int>>> sortedMeetings;
        sort(meetings.begin(), meetings.end(), 
        [](const vector<int>& a, const vector<int>& b) 
        {
            return a[2] < b[2];
        });

        set<int> seenTime;
        
        for (const auto& meeting : meetings) {
            if (seenTime.find(meeting[2]) == seenTime.end()) {
                seenTime.insert(meeting[2]);
                sortedMeetings.push_back({});
            }
            sortedMeetings.back().push_back({meeting[0], meeting[1]});
        }

        for (const auto& meetingGroup : sortedMeetings) {
            set<int> peopleKnowSecret;
            unordered_map<int, vector<int>> graph;
            
            for (const auto& pair : meetingGroup) {
                graph[pair.first].push_back(pair.second);
                graph[pair.second].push_back(pair.first);
                
                if(ans.find(pair.first) != ans.end()) 
                peopleKnowSecret.insert(pair.first);
                if(ans.find(pair.second)!=ans.end())                    
                peopleKnowSecret.insert(pair.second);
            }
            
            queue<int> queue;
            for (int person : peopleKnowSecret) queue.push(person);
        
            while (!queue.empty()) {
                int curr = queue.front();
                queue.pop();
                ans.insert(curr);
                for (int neigh : graph[curr]) {
                    if (ans.find(neigh) == ans.end()) {
                        ans.insert(neigh);
                        queue.push(neigh);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};