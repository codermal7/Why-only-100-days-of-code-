class Solution {
public:
    unordered_map<char, int> mp, sc;
    int ans, n;

    int ok(string& word){
        int ans = 0;
        for (int i = 0; i < word.size(); i++){
            char x = word[i];
            if (mp[x] > 0){ mp[x]--; ans += sc[x]; }
            else{
                for (int j = i-1; j >= 0; j--){
                    mp[word[j]]++;
                } 
                return 0; 
            }
        }
        return ans;
    }

    void solve(vector<string>& words, int i, int sum){
        if(i >= n){
            ans = max(ans, sum);
            return ;
        }
        int possible = ok(words[i]);
        if (possible){
            solve(words, i+1, sum+possible);
            for (auto &x : words[i]) mp[x]++;
        }
        solve(words, i+1, sum);

    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        int i = 97;
        ans = 0;
        for (auto &x: letters) mp[x] += 1;
        for (auto &x: score) sc[i++] = x;

        solve(words, 0, 0);
        return ans;
    }
};