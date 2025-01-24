class Solution {
public:
bool dfs(vector<vector<int>>&graph,map<int,int>&mp,vector<bool>&isVisit,int node){
    if(node>=graph.size())return true;
    if(isVisit[node])return false;
    bool res=true;
    isVisit[node]=true;
    for(auto x:graph[node]){
        if(mp.find(x)!=mp.end())continue;
        res=(res&&dfs(graph,mp,isVisit,x));
    }
    if(res)mp[node]++;
    return res;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int,int>mp;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0)mp[i]++;
        }
        vector<bool>isVisit(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            
        bool x=dfs(graph,mp,isVisit,i);
        }
        vector<int>ans;
        for(auto x:mp){
            ans.push_back(x.first);
        }
        return ans;
    }
};