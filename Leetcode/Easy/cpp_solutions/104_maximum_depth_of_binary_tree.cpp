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
    
    int sol (TreeNode* root, int depth) {
        if (!root) {
            return depth;
        }
        
        depth++;
        return max(sol(root->left, depth), sol(root->right, depth));
    }
    
    int maxDepth(TreeNode* root) {
        return sol(root, 0);
    }
};






                    int main(void) 