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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        
        if (!root) return ret;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            int num_nodes = q.size();
            vector<int> nodes;

            while (num_nodes > 0) {
                TreeNode *node = q.front();
                q.pop();
            
                if (node->left) {
                    q.push(node->left);
                } 

                if (node->right) {
                    q.push(node->right);
                }
                
                nodes.push_back(node->val);
                
                num_nodes--;
            }
            
            ret.insert(ret.begin(), nodes);
        }
        
        return ret;
    }
};
