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
     TreeNode* build(vector<int>& preorder, int& preIndex,
                    int inStart, int inEnd,
                    unordered_map<int,int>& mp){

        if(inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int pos = mp[root->val];

        root->left = build(preorder, preIndex,
                           inStart, pos - 1, mp);

        root->right = build(preorder, preIndex,
                            pos + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int preIndex = 0;

        return build(preorder, preIndex,
                     0, inorder.size() - 1, mp);
        
    }
};