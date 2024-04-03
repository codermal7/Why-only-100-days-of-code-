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
    void solutionn(TreeNode* root, vector<int> &vect)
    {
        if(root == NULL)
        return;
        solutionn(root->left,vect);
        solutionn(root->right,vect);    
        vect.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vect;
        solutionn(root, vect);
        return vect;    
    }
};