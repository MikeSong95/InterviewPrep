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
    int sum;
    
    void sol(TreeNode* root, int L, int R) {
        if (root == NULL) {
            return;
        }
        
        if (root->val >= L && root->val <= R) {
            sum += root->val;
        }
        
        if (root->val > L) {
            sol(root->left, L, R);
        } 
        
        if (root->val < R) {
            sol(root->right, L, R);
        } 
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum = 0;
        sol(root, L, R);
        return sum;
    }
};