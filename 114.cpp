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
    void flatten(TreeNode* root) {
        help(root);
    }

    TreeNode* help(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left) {
            if (!root->right) {
                return root;
            }
            else {
                return help(root->right);
            }
        }
        else {
            if (!root->right) {
                TreeNode* lr = help(root->left);
                root->right = root->left;
                root->left = nullptr;
                return lr;
            }
            else {
                TreeNode* lr = help(root->left);
                TreeNode* rr = help(root->right);
                lr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                return rr;
            } 
        }
    }
};