/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *>qt;
        if(root==nullptr ) return root;
        qt.push(root);
        while(!qt.empty()){
            int x=qt.size();
            for(int i=0;i<x;i++){
                auto it  =qt.front();
                qt.pop();
                if(i<x-1){
                    it->next = qt.front();
                }
                if(it->left !=nullptr){
                    qt.push(it->left);
                }
                if(it->right !=nullptr){
                    qt.push(it->right);
                }
            }
        }
        return root;
    }
};