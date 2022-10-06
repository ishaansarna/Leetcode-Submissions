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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if (!root)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.first->val >= p.second)
                ans++;
            if (p.first->left)
                q.push(make_pair(p.first->left, max(p.second, p.first->val)));
            if (p.first->right)
                q.push(make_pair(p.first->right, max(p.second, p.first->val)));
        }
        return ans;
    }
};