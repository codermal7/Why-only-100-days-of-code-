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
class FindElements {
public:
    unordered_set<int> values;

    void reconstruct(TreeNode* node) {
        if (!node) return;

        if (node->left) {
            node->left->val = 2 * node->val + 1;
            values.insert(node->left->val);
            reconstruct(node->left);
        }
        if (node->right) {
            node->right->val = 2 * node->val + 2;
            values.insert(node->right->val);
            reconstruct(node->right);
        }
    }

    FindElements(TreeNode* root) {
        if (!root) return;
        root->val = 0;
        values.insert(0);
        reconstruct(root);
    }
    
    bool find(int target) {
        return values.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */