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
    TreeNode * solve(int low ,int high ,vector<int>& nums){
        if(low>high) return nullptr;
        int x = (low+(high-low)/2);
        TreeNode * root = new TreeNode(nums[x]);

        root->left = solve(low ,x-1 ,nums);
        root->right = solve(x+1,high ,nums);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n  = nums.size();
        int low =0;
        int high = n-1;
        return solve(low ,high ,nums);

    }
};