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

bool solve(TreeNode* root, int k,unordered_map<int,int>&um){
    if (!root) return false;
    int x= k-root->val;
    if(um.find(x)!=um.end()) return true;
    um[root->val]++;
    bool left1 = solve(root->left , k ,um);
    bool right1 = solve(root->right , k ,um);
    return left1||right1;
}


public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>um;
        return solve(root ,k ,um);

    }
};