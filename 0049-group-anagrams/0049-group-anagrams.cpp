class Solution {
public:
    string generateWord(string& word)
    {
        int arr[26]={0};
        for(char ch:word)
        {
            arr[ch-'a']++;
        }
        string new_word="";
        for(int i=0;i<26;i++)
        {
            int freq=arr[i];
            if(freq>0)
            new_word+=string(freq,i+'a');
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string word=strs[i];
            string new_word=generateWord(word);
            mp[new_word].push_back(word);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};