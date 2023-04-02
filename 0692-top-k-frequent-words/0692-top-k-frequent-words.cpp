class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        vector<int> v;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int i=0;
        words.clear();
        while(i<k){
            for(auto it:mp){
                if(it.second==v[v.size()-1]){
                    words.push_back(it.first);
                    mp.erase(it.first);
                    break;
                }
            } 
            v.pop_back();
            i++; 
        }
        return words;
    }
};