class Solution {
public:

    map<TreeNode*,TreeNode*> parent;
    map<TreeNode*,int> depth;

    void dfs(TreeNode* root, TreeNode* par, int d){
        if(root == NULL) return;

        parent[root] = par;   // store parent
        depth[root] = d;      // store depth

        dfs(root->left, root, d+1);
        dfs(root->right, root, d+1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, NULL, 0);   // build parent + depth

        // ✅ Step 1: bring both to same depth
        while(depth[p] > depth[q]){
            p = parent[p];
        }

        while(depth[q] > depth[p]){
            q = parent[q];
        }

        // ✅ Step 2: jump together
        while(p != q){
            p = parent[p];
            q = parent[q];
        }

        return p;   // or q (both same now)
    }
};