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
    vector<int> vect;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL)
        {
            vect.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return vect;
    }
};