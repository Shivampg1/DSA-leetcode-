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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) {
            return -1;
        }
        
        int min_val = root->val;
        long long second_min = LLONG_MAX;  // Use long long to handle INT_MAX cases
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            
            if (node->val > min_val && node->val < second_min) {
                second_min = node->val;
            }
            
            if (node->val == min_val) {
                if (node->left) {
                    stk.push(node->left);
                }
                if (node->right) {
                    stk.push(node->right);
                }
            }
        }
        
        return (second_min != LLONG_MAX) ? static_cast<int>(second_min) : -1;
    }
};