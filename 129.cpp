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
private:
    vector<int> list;
public:
    void dfs(TreeNode* root, int num) {
        num = num * 10 + root->val;
        if (!(root->left) && !(root->right)) {
            list.emplace_back(num);
            return;
        }
        if (root->left) {
            if (root->right) {
                dfs(root->left, num);
                dfs(root->right, num);
            }
            else dfs(root->left, num);
        }
        else dfs(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        int sum = 0;
        for (int i = 0; i < list.size(); i++) sum += list[i];
        return sum;
    }
};