class Solution {
public:
    typedef pair<char,int> p;
    string frequencySort(string s) {
        // map<char,int> mp;
        // multimap<int,char> r;
        // string ss="";

        // for(auto a : s)
        //     mp[a]++;

        // for(auto a : mp)
        //     r.insert({a.second, a.first});

        // for(auto it = r.rbegin(); it != r.rend(); ++it){
        //     ss += string(it->first, it->second);
        // }

        // return ss;
        string res="";
        vector<p> vec(123);
        for(char ch:s)
        {
            vec[ch].first = ch;
            vec[ch].second++;
        }
        
        auto comp = [&](p &a, p &b) {
            return a.second > b.second;
        };
        sort(vec.begin(),vec.end(),comp);
        for(auto it:vec)
        {
            if(it.second>0)
            res+=string(it.second,it.first);
        }
        return res;
    }
};