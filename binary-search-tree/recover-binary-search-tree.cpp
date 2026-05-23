class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                // process node
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while (temp->right && temp->right != curr)
                    temp = temp->right;

                if (!temp->right) {
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    temp->right = NULL;

                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};