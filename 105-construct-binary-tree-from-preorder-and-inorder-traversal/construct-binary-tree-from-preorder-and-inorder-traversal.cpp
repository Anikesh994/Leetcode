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
    int t=0;
    TreeNode * solve(int i,int j ,unordered_map<int,int>&um,vector<int>& preorder,vector<int>& inorder ){
        if(i>j) return nullptr;
        TreeNode * root = new TreeNode(preorder[t]);
        t++;
        root->left =solve(i,um[root->val]-1,um,preorder,inorder);
        root->right =solve(um[root->val]+1,j,um,preorder,inorder);
        return root;
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * root =new TreeNode(preorder[0]);
        unordered_map<int,int>um;
        for(int i =0;i<inorder.size();i++){
            um[inorder[i]]=i;
        }
        return solve(0,preorder.size()-1, um,preorder ,inorder);
        

    }
};