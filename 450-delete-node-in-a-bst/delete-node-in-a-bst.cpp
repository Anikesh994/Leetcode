/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    TreeNode* solve(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key)
            return solve1(root);
        if (root->val > key)
            root->left =  solve(root->left, key);
        else {
            root->right = solve(root->right, key);
        }

        return root;
    }

    TreeNode * solve1(TreeNode* root) {
        if (!root)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = root->left;

        while(temp->right != nullptr){
            temp=temp->right;
        }
        temp->right =root->right;
        TreeNode* newRoot = root->left;
        delete root;
        return newRoot;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root ,key);
    }
};