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
    stack<int> s;
    int k;
    void inorder (TreeNode* curr) {
        if (s.size() == k || !curr)
            return;
        inorder(curr->left);
        if (s.size() == k)
            return;
        else 
            s.push(curr->val);
        inorder(curr->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        auto curr = root;
        this->k = k;
        inorder(root);
        return s.top();
    }
};