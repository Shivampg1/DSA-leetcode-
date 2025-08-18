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
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        int min_value = INT_MAX;

        for(int i=1;i<ans.size();i++){
            int res= abs(ans[i]-ans[i-1]);
              //return min_value=min(res,min_value);
              if((min(res,min_value))<min_value){
                    min_value=res;
              }
        }
        return min_value;
    }
    void inorder(TreeNode*node, vector<int> &ans){
        if(node==NULL){
            return;
        }
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }

};