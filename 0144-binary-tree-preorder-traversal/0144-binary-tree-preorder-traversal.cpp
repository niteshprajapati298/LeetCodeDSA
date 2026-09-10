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
    void preOrderTraverse(TreeNode* root, vector<int>&ans ){
        if(root==nullptr) return;
        ans.push_back(root->val);
        // preOrderTraverse(root,ans);
        preOrderTraverse(root->left,ans);
        preOrderTraverse(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrderTraverse(root,ans);
        return ans;
    }
};