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
    int sol(TreeNode* root, int depth) {        
        depth++;
        
        if (root->left && root->right) {
            return min(sol(root->left, depth), sol(root->right, depth));
        } else if (!root->left && root->right) {
            return sol(root->right, depth);
        } else if (root->left && !root->right) {
            return sol(root->left, depth);
        } else {
            return depth;
        }
    }
    
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        return sol(root, 0);
    }
};