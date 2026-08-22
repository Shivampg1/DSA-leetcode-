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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,unsigned long long>>q;
        int src=1;
        q.push({root,src});
        int max_val=-1;
       while(!q.empty()){
        int siz=q.size();
        vector<unsigned long long>ans;
        for(int i=0;i<siz;i++){
            TreeNode* curr=q.front().first;
            unsigned long long idx=q.front().second;
            q.pop();
             ans.push_back(idx);
            if(curr->left){
                q.push({curr->left,idx*2});
            }
            if(curr->right){
                q.push({curr->right,idx*2+1});
            }
        }
        int width = ans[ans.size()-1] - ans[0] + 1;
        max_val=max(max_val,width);

       }
       return max_val;
    }
};