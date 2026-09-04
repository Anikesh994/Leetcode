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
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*  ,long long>>qt;
        qt.push({root ,0});
        long long ans=0;
        while(!qt.empty()){
            int n=qt.size();
            long long l=0,r=0;
            long long temp = qt.front().second;
            for(int i=0;i<n;i++){
                auto it = qt.front();
                qt.pop();
                long long  y = it.second-temp;
                if(i==0) l =y;
                if(i==n-1) r =y;
                if(it.first->left){
                    qt.push({it.first->left , (2*y)+1});
                }
                if(it.first->right){
                    qt.push({it.first->right , (2*y)+2});
                }
                
            }
            ans =max(ans,r-l+1);
        }
        return ans;
    }
};