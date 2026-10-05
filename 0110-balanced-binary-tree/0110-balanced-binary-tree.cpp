/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        int heightDiff = leftHeight - rightHeight;
        cout << "Left Height is " << leftHeight << " Right Height is "
             << rightHeight << " at root Node " << root->val << endl;
        if (heightDiff == 1 || heightDiff == -1 || heightDiff == 0) {
            bool leftBalanced = isBalanced(root->left);
            bool rightBalanced = isBalanced(root->right);
            return leftBalanced && rightBalanced;
        }
        cout << " Reached At Line 32" << endl;
        return false;
    }
};