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
    vector<vector<int>> sol(TreeNode* root, int sum, vector<int> path, vector<vector<int>> ret) {       
        sum -= root->val;
        path.push_back(root->val);

        if (root->left && root->right) {
            ret = sol(root->left, sum, path, ret);
            ret = sol(root->right, sum, path, ret);
        } else if (root->left && !root->right) {
            ret = sol(root->left, sum, path, ret);
        } else if (!root->left && root->right) {
            ret = sol(root->right, sum, path, ret);
        } else { 
            if (sum == 0) {
                ret.push_back(path);
                return ret;
            } 
        }
        
        return ret;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        
        if (!root) {
            return ret;
        } else {
            vector<int> p;
        
            return sol(root, sum, p, ret);
        }
    }
};