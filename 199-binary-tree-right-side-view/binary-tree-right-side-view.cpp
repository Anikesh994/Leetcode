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
    void f(TreeNode * root,int i,vector<int>&mp){
        if(root==nullptr){
            return;
        }
        if(mp[i]==1e4){
            mp[i]=root->val;
        }
        f(root->right,i+1,mp);
        f(root->left,i+1,mp);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>mp(100 ,1e4);
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        f(root,0,mp);
        
        for(int i=0;i<100;i++){
            if(mp[i]==1e4) break;
            ans.push_back(mp[i]);
        }
        return ans;
    }
};