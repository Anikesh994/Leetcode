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
int q=0;
TreeNode * solve(int low ,int high ,unordered_map<int,int>&um ,vector<int>& preorder ){
    if(low >high) return nullptr;
    TreeNode * root = new TreeNode(preorder[q]);
    q++;
    TreeNode * l1 = solve(low , um[root->val]-1 ,um,preorder );
    TreeNode * r1 = solve(um[root->val]+1,high ,um,preorder );
    root->left =l1;
    root->right =r1;
    return root;

}



public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>um;
        int n =inorder.size();
        for(int i=0;i<n;i++){
            um[inorder[i]]=i;
        }
        return solve(0,n-1,um ,preorder);
    }
};