class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> number = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string just = "";
        vector<string> ans;
        vector<string> temp;
        for(int digit : digits) {
            digit -= 48;
            ans.clear();
            for(int i = 0; i < number[digit].length(); ++i) {
                if(temp.size() == 0) {
                    ans.push_back(just + number[digit][i]);
                }
                else {
                    for(string s : temp)
                        ans.push_back(s + number[digit][i]);
                }
            }
            temp = ans;
        }        
        return ans;
    }
};