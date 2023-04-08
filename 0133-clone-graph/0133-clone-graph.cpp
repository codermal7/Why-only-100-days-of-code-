class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* root = new Node(node->val);
        vector<pair<int,Node*>>vis(101,{0,NULL});
        vis[node->val]={1,root};
        queue<pair<Node*,Node*>>q;
        q.push({node,root});
        while(!q.empty()){
            Node* temp=q.front().first;
            Node* r=q.front().second;
            q.pop();
            for(auto j:r->neighbors){
                if(j->val==temp->val) {r=j; break;}
            }
            for(auto i:temp->neighbors){
               
                if(vis[i->val].first==0){
                    Node* t=new Node(i->val);
                    r->neighbors.push_back(t);
                    vis[i->val]={1,t};
                    q.push({i,r});
                }
                else{
                    r->neighbors.push_back(vis[i->val].second);
                }
            }
        }
        return root;
    }
};