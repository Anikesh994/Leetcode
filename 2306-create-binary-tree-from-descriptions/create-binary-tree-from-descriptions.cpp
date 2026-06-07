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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n =descriptions.size();
        unordered_map<int , int>um;
        unordered_map<int , TreeNode *>um1;
        for(int i=0;i<n;i++){
            um[descriptions[i][1]]++;
            um[descriptions[i][0]]++;
        }
        for(auto it : um){
            um1[it.first] = new TreeNode(it.first);
        }
        for(int i=0;i<n;i++){
            if(descriptions[i][2]==1){
                um1[descriptions[i][0]]->left =um1[descriptions[i][1]];
            }
            else{
                um1[descriptions[i][0]]->right =um1[descriptions[i][1]];
            }
        }
        for(int i=0;i<n;i++){
            um.erase(descriptions[i][1]);
        }
        int x;
        for(auto it : um){
            x=it.first;
        }
        return um1[x];
        
    }
};