#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode *root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

void preorder(TreeNode *root) {
    if (!root) return;

    cout << root->val << endl;
    inorder(root->left);
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if (!root) return;
    
    inorder(root->right);
    inorder(root->left);
    cout << root->val << endl;
}

void level_order(queue<TreeNode *> frontier) {
    queue<TreeNode *> next;

    while (!frontier.empty()) {
        TreeNode *r = frontier.front();
        frontier.pop();

        cout << r->val << endl;

        if (r->left) next.push(r->left);
        if (r->right) next.push(r->right);
    }

    if (!next.empty()) {
        level_order(next);
    }

    return;
}

int main(void) {
    // Build Binary Tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);

    cout << "Inorder: " << endl;
    inorder(root);
    cout << "Preorder: " << endl;
    preorder(root);
    cout << "Postorder: " << endl;
    postorder(root);
    cout << "Level Order: " << endl;
    queue<TreeNode *> f;
    f.push(root);
    level_order(f);

    return 0;
}