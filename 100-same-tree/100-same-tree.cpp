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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p && !q) || (q && !p))
            return false;
        if (!p && !q)
            return true;
        if (p->left || q->left) {
            if ((p->left && !q->left) || (q->left && !p->left))
                return false;
            if (p->left->val != q->left->val)
                return false;
        }
        if (p->right || q->right) {
            if ((p->right && !q->right) || (q->right && !p->right))
                return false;
            if (p->right->val != q->right->val)
                return false;
        }
        if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
            return false;
        return p->val == q->val;
    }
};