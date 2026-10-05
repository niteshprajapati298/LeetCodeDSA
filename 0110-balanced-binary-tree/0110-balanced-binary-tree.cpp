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
    int findHeight(TreeNode* root,int &valid) {
        if (root == nullptr) {
            return 0;
        }
        int left = findHeight(root->left,valid);
        int right = findHeight(root->right,valid);
        if(abs(left-right)>1) valid = 0;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
         int valid = 1;
         int height = findHeight(root,valid);
         if(valid ==1 ) return true;
         return false;

        // int leftHeight = findHeight(root->left);
        // int rightHeight = findHeight(root->right);
        // int heightDiff = leftHeight - rightHeight;
        // cout << "Left Height is " << leftHeight << " Right Height is "
        //      << rightHeight << " at root Node " << root->val << endl;
        // if (heightDiff == 1 || heightDiff == -1 || heightDiff == 0) {
        //     bool leftBalanced = isBalanced(root->left);
        //     bool rightBalanced = isBalanced(root->right);
        //     return leftBalanced && rightBalanced;
        // }
        // return false;
    }
};