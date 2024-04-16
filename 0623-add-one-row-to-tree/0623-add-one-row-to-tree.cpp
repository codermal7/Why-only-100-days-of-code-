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
    void solve(TreeNode *&root, int val, int target, int depth, bool side)
    {
        if(depth == target)
        {
            TreeNode* temp = new TreeNode(val);
            if(root) 
            {
                if(side) temp->left = root;
                else temp->right = root;
            }
            root = temp;
            return;
        }
        if(!root) return;
        solve(root->left, val, target, depth+1, true);
        solve(root->right, val, target, depth+1, false);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1) 
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root, val, depth, 1, false);
        return root;
    }
};