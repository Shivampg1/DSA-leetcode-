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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
    vector<int> modes;
    int currentVal = 0;
    int currentCount = 0;
    int maxCount = 0;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        handleValue(root->val);
        inorder(root->right);
    }

    void handleValue(int val) {
        if (val != currentVal) {
            currentVal = val;
            currentCount = 0;
        }
        currentCount++;
        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes.clear();
            modes.push_back(val);
        } else if (currentCount == maxCount) {
            modes.push_back(val);
        }
    }
   
};