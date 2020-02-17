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
    bool sol(TreeNode* root, int sum) {        
        if (!root) {
            if (sum == 0) {
                return true;
            } else {
                return false;
            }
        }
        
        sum -= root->val;

        if (root->left && root->right) {
            return sol(root->left, sum) || sol(root->right, sum);
        } else if (root->left && !root->right) {
             return sol(root->left, sum);
        } else {
             return sol(root->right, sum);
        }
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        else return sol(root, sum);
    }
};