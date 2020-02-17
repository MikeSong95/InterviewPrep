/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int sol (TreeNode* root, int sum) {
        sum = sum * 10;
        sum += root->val;
        
        if (root->left && root->right) {
            sum = sol(root->left, sum) + sol(root->right, sum);
        } else if (root->left && !root->right) {
            sum = sol(root->left, sum);
        } else if (!root->left && root->right) {
            sum = sol(root->right, sum);
        } else { 
            return sum;
        }
        
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            return sol(root, 0);
        }
    }
};