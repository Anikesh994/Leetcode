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

pair<TreeNode *,TreeNode *> solve(TreeNode * root){
    if(root==nullptr) return {nullptr,nullptr};
    auto it1 = solve(root->left);
    auto it2 = solve(root->right);
    root->left = nullptr;
    if((it1.first == nullptr && it1.second == nullptr) && (it2.first == nullptr && it2.second == nullptr)){
        return {root,root};
    }
    if(it1.first == nullptr && it1.second == nullptr){
        return {root ,it2.second};
    }
    if(it2.first == nullptr && it2.second == nullptr){
        root->right = it1.first;
        return {root ,it1.second};
    }
    root->right  = it1.first;
    it1.second->right = it2.first;
    return {root ,it2.second};
}


public:
    void flatten(TreeNode* root) {
        solve(root);
        
    }
};