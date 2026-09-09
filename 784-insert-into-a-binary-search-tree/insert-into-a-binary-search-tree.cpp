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

void solve(TreeNode * root , int x , TreeNode * par){
    if(!root){
        if(par->val > x){
            par->left = new TreeNode(x);
        }
        else{
            par->right = new TreeNode(x);
        }
        return;
    }
    if(root->val >x){
        solve(root->left ,x,root);
    }
    else{
        solve(root->right ,x,root);
    }
        
}

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode * ans =root;
        solve(root ,val,nullptr);
        return ans;
    }
};