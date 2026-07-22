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

    string serialize(TreeNode* root) {
         if(root == NULL)
            return "";

        queue<TreeNode*> q;
        q.push(root);

        string ans = "";

        while(!q.empty()){

            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL){
                ans += "N ";
            }
            else{
                ans += to_string(curr->val) + " ";

                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        
        if(data.size() == 0)
            return NULL;

        // Convert string into stream
        stringstream ss(data);

        string str;

        // Read first value (root)
        getline(ss, str, ' ');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* curr = q.front();
            q.pop();

            // Left child
            getline(ss, str, ' ');

            if(str != "N"){
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }

            // Right child
            getline(ss, str, ' ');

            if(str != "N"){
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));