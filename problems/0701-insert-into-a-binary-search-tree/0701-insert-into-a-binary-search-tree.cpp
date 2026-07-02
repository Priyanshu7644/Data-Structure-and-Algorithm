class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);

        if (root == nullptr)
            return newNode;

        TreeNode* dummy = root;

        while (true) {
            if (val < dummy->val) {
                if (dummy->left == nullptr) {
                    dummy->left = newNode;
                    break;
                }
                dummy = dummy->left;
            } else {
                if (dummy->right == nullptr) {
                    dummy->right = newNode;
                    break;
                }
                dummy = dummy->right;
            }
        }

        return root;
    }
};