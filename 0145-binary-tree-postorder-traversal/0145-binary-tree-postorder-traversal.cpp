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
    // void traverse(TreeNode* root, vector<int>&ans){
    //     if(root==nullptr) return;
    //     traverse(root->left,ans);
    //     traverse(root->right,ans);
    //     ans.push_back(root->val);
    // }
    void traverseIterative(TreeNode* root,vector<int>&ans){
           stack<TreeNode*>st;
           st.push(root);
          while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left ) st.push(temp->left);            
            if(temp->right ) st.push(temp->right);

          }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        traverseIterative(root, ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};