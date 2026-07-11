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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        bool lhrh=true;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>lev(size);

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                int idx= lhrh ? i : size-1-i;
                lev[idx]=node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            lhrh=!lhrh;
            ans.push_back(lev);
        }
        return ans;
    }
};