/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if (!root) return s;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=NULL){
                s+=to_string(temp->val)+",";
                q.push(temp->left);
                q.push(temp->right);
            }
            else{
                s+="N,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }

        stringstream ss(data);
        string temp;
        vector<string>arr;

        while(getline(ss,temp,',')){
            if(!temp.empty()){
                arr.push_back(temp);
            }
        }

        TreeNode* root=new TreeNode(stoi(arr[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i=1;
        while(!q.empty() && i<arr.size()){
            TreeNode* t=q.front();
            q.pop();
             if (arr[i] != "N") {
                t->left = new TreeNode(stoi(arr[i]));
                q.push(t->left);              
            }
            i++;

            if (arr[i] != "N") { 
                t->right = new TreeNode(stoi(arr[i]));
                q.push(t->right);
            }
            i++;
        }
    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));