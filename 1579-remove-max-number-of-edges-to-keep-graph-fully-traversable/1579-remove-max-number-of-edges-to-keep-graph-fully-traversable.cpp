class DSU{
private:
    vector<int>parent,rank;
public:
    DSU(int size){
        parent.resize(size);
        rank.resize(size);
        for(int i=0;i<size;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x!=parent[x]) parent[x]=find(parent[x]);
        return parent[x];
    }
    void Union(int x,int y){
        int xs=find(x),ys=find(y);
        if(xs==ys) return;
        if(rank[xs]>rank[ys]) parent[ys]=xs,find(y);
        else if(rank[xs]<rank[ys]) parent[xs]=ys,find(x);
        else{
            rank[xs]++;
            parent[ys]=xs;
            find(y);
        }
    }
    bool needed(int x,int y){
        int xs=find(x),ys=find(y);
        return xs!=ys;
    }
    bool done(){
        unordered_set<int>s;
        for(int i=0;i<parent.size();i++){
            find(i);
            s.insert(parent[i]);
        }
        return s.size()==1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](auto &x1,auto &x2){return x1[0]>x2[0];});
        DSU alice(n),bob(n);
        int ans=0;
        for(auto &x:edges){
            if(x[0]==3){
                if(alice.needed(x[1]-1,x[2]-1)){
                    alice.Union(x[1]-1,x[2]-1);
                    bob.Union(x[1]-1,x[2]-1);
                }
                else ans++;
            }
            else if(x[0]==1){
                if(alice.needed(x[1]-1,x[2]-1)) alice.Union(x[1]-1,x[2]-1);
                else ans++;
            }
            else{
                if(bob.needed(x[1]-1,x[2]-1)) bob.Union(x[1]-1,x[2]-1);
                else ans++;
            }
        }
        if(alice.done() && bob.done()) return ans;
        else return -1;
    }
};