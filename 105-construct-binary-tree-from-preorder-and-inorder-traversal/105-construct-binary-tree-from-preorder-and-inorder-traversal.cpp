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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if (!preorder.empty() && !inorder.empty()) {
            TreeNode* root = new TreeNode(preorder[0]);
            int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
            root->left = buildTree(vector<int>(preorder.begin()+1, preorder.begin()+mid+1), vector<int>(inorder.begin(), inorder.begin()+mid));
            root->right = buildTree(vector<int>(preorder.begin()+mid+1, preorder.end()), vector<int>(inorder.begin()+mid+1, inorder.end()));
            return root;
        }
        else
            return nullptr;
    }
};