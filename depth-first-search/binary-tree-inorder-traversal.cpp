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
 */class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        
        while (root != NULL || !st.empty()) {
            
            // Go as left as possible
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            
            // Process node
            root = st.top();
            st.pop();
            result.push_back(root->val);
            
            // Move to right subtree
            root = root->right;
        }
        
        return result;
    }
};