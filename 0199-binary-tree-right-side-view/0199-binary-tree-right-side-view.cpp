/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // if (root == NULL) return ans;
        // queue<pair<TreeNode*, int>> q;
        // q.push({root,0});
        // map<int,int> mp;
        // while(!q.empty())
        // {
        //     auto it=q.front();
        //     q.pop();
        //     TreeNode* node=it.first;
        //     int line=it.second;
        //     mp[line]=node->val;
        //     if(node->left != NULL)
        //     q.push({node->left,line+1});
        //     if(node->right != NULL)
        //     q.push({node->right,line+1});
        // }
        // for(auto i:mp)
        // ans.push_back(i.second);
        // return ans;
        if(root==NULL) return ans;
        rightView(ans,root,0);
        return ans;
    }
    void rightView(vector<int> &ans,TreeNode* root,int line)
    {
        if(root==NULL) return;
        if(line==ans.size())
        ans.push_back(root->val);
        rightView(ans,root->right,line+1);
        rightView(ans,root->left,line+1);
    }
};