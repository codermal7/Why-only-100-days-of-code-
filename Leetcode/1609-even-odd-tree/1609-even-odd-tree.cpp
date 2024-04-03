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
// class Solution {
// public:
//     unordered_map<int,int > mp;
//     bool dfs(TreeNode* root, int level )
//     {
//         if(root == NULL)
//         return true;

//         if(level & 1)
//         {
//             if (root->val  &  1)
//             return false;
//         }
//         else if(!(root->val & 1))
//         return false;
        
//         if (mp.find(level) != mp.end())
//         {
//             if(level & 1 ){
//                 if(mp[level] <= root->val) return false; 
//             }
//             else if(mp[level] >= root->val ) return false; 
//         }
        
//         mp[level] =  root->val;
    
//         return dfs(root->left , level + 1) && dfs(root->right, level +  1);
//     }
//     bool isEvenOddTree(TreeNode* root) {
//         return dfs(root, 0 );   
//     }
// };
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lv = 0;
        while (q.size()) {
            int cnt = q.size(), prev = lv % 2 == 0 ? 0 : INT_MAX;
            while (cnt--) {
                auto node = q.front();
                q.pop();
                if (lv % 2 == 0) {
                    if (node->val % 2 == 0 || node->val <= prev) return false;
                } else {
                    if (node->val % 2 || node->val >= prev) return false;
                }
                prev = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++lv;
        }
        return true;
    }
};