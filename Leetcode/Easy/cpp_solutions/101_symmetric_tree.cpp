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
    bool traverse(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p && q || p && !q) {
            return false;
        }
        
        if (p->val == q->val) {
            return traverse(p->left, q->right) && traverse(p->right, q->left);
        } else {
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return traverse(root->left, root->right);
    }
};