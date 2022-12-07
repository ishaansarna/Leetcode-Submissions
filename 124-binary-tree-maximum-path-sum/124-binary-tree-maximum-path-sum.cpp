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
    int maxAtNode(TreeNode* root, int& res) {
        int right, left;
        if (root->left)
            left = maxAtNode(root->left, res);
        else
            left = 0;
        if (root->right)
            right = maxAtNode(root->right, res);
        else
            right = 0;
        int split = root->val + right + left;
        int no_split = max(left, max(right, 0)) + root->val;
        res = max(res, max(split, no_split));
        return no_split;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxAtNode(root, res);
        return res;
    }
};