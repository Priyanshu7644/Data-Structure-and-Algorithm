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
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }

    pair<bool,int>helper(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }

        auto[bleft,hleft]=helper(root->left);
        auto[bright,hright]=helper(root->right);

        bool balanced=bleft && bright && abs(hleft-hright)<=1;
        int height=1+max(hleft,hright);
        return {balanced,height};
    }
};