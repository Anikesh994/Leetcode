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
int i=0;
TreeNode * solve(vector<int>& preorder ,int temp){
    if(i==preorder.size() || preorder[i] > temp) return nullptr;
    TreeNode * root = new TreeNode(preorder[i++]);
    root->left = solve(preorder ,root->val);
    root->right =solve(preorder ,temp);
   
    return root;
}



public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder ,INT_MAX);
    }
};