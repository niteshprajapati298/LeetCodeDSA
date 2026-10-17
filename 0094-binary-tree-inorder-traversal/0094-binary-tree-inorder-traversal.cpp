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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> st;
        stack<bool> visited;
        st.push(root);
        visited.push(0);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            bool flag = visited.top();
            visited.pop();
            st.pop();
            if (!flag) {
                if (temp->right!=nullptr) {
                    st.push(temp->right);
                    visited.push(0);
                }
                st.push(temp);
                visited.push(1);
                if (temp->left!=nullptr) {
                    st.push(temp->left);
                    visited.push(0);
                }
            }
            else {
                ans.push_back(temp->val);
            }
        }
        return ans;
    }
};