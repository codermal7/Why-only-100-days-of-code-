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

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = [](){ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return 'c'; 
}();


class Solution 
{
    public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = 100000;
        vector<int> nodeDepths(n + 1, 0);
        vector<int> subtreeHeights(n + 1, 0);
        vector<int> firstLargestHeight(n + 1, 0);
        vector<int> secondLargestHeight(n + 1, 0);
        dfs(root, 0, nodeDepths, subtreeHeights, firstLargestHeight,
        secondLargestHeight);
        vector<int> results;
        results.reserve(queries.size());
        for (int queryNode : queries) {
            int nodeLevel = nodeDepths[queryNode];
            if (subtreeHeights[queryNode] == firstLargestHeight[nodeLevel]) {
                results.push_back(nodeLevel + secondLargestHeight[nodeLevel] -
                                  1);
            } else {
                results.push_back(nodeLevel + firstLargestHeight[nodeLevel] -
                                  1);
            }
        }
        return results;
    }

    private:
    int dfs(TreeNode* node, int level, vector<int>& nodeDepths,
            vector<int>& subtreeHeights, vector<int>& firstLargestHeight,
            vector<int>& secondLargestHeight) 
    {
        if (node == nullptr) 
        return 0;
        nodeDepths[node->val] = level;
        int leftHeight = dfs(node->left, level + 1, nodeDepths, subtreeHeights,
                            firstLargestHeight, secondLargestHeight);
        int rightHeight =
            dfs(node->right, level + 1, nodeDepths, subtreeHeights,
                firstLargestHeight, secondLargestHeight);
        int currentHeight = 1 + max(leftHeight, rightHeight);

        subtreeHeights[node->val] = currentHeight;
        if (currentHeight > firstLargestHeight[level]) {
            secondLargestHeight[level] = firstLargestHeight[level];
            firstLargestHeight[level] = currentHeight;
        } else if (currentHeight > secondLargestHeight[level]) {
            secondLargestHeight[level] = currentHeight;
        }

        return currentHeight;
    }
};