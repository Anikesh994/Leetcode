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

void dfs(TreeNode * root ,unordered_map<TreeNode *  ,TreeNode *>&um ){
    if(!root) return;
    if(root->left){
        um[root->left] = root;
    }
    if(root->right){
        um[root->right] = root;
    }
    dfs(root->left ,um);
    dfs(root->right ,um);
}

void solve(TreeNode* node,TreeNode * par, vector<int>&ans ,unordered_map<TreeNode *  ,TreeNode *>&um,int k ){
    if(!node) return;
    if(k==0){
        ans.push_back(node->val);
        return;
    }

    if(node->left != par){
        solve(node->left , node ,ans,um,k-1);
    }
    if(node->right != par){
        solve(node->right , node ,ans,um,k-1);
    }
    if(um.find(node)!=um.end() && um[node]!=par){
        solve(um[node] , node ,ans,um,k-1);
    }

}

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *  ,TreeNode *>um;
        vector<int>ans;
        dfs(root,um);
        solve(target ,nullptr ,ans,um,k);
        return ans;
    }
};