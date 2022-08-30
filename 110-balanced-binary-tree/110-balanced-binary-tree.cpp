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
    pair<bool, int> dfs(TreeNode* root) {
        if (!root)
            return make_pair(true, 0);
        auto left_pair = dfs(root->left);
        auto right_pair = dfs(root->right);
        bool balanced = left_pair.first && right_pair.first
            && (abs(left_pair.second - right_pair.second) <= 1);
        int height = max(left_pair.second, right_pair.second) + 1;
        return make_pair(balanced, height);
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};