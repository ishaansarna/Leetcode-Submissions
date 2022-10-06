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
    int ans;
    void help(TreeNode* root, int h) {
        if (!root)
            return;
        if (root->val >= h)
            ans++;
        help (root->left, max(h, root->val));
        help (root->right, max(h, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        ans = 0;
        help(root, INT_MIN);
        return ans;
    }
};