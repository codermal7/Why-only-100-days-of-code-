class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for(int x : students) {
            q.push(x);
        }
        int n = students.size();

        for(int i = 0; i < n; i++) {
            int q_size = q.size();
            bool keep_going = true;
            for(int j = 0; j < q_size && keep_going; j++) {
               
                int next_pref = q.front();
                q.pop();

                if(next_pref == sandwiches[i]) {
                    keep_going = false;
                    break;
                } else {
                    q.push(next_pref);
                }
                
            }
            if(q.size() == q_size) {
                return q_size;
            }
        }

        return 0;
    }
};